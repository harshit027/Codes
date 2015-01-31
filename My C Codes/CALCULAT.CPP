/*a mini digital calculator : HARSHIT*/

#include"iostream.h"
#include"conio.h"
#include"math.h"
#include"stdio.h"
#include"graphics.h"
#include"dos.h"
#include"process.h"
#include"stdlib.h"


/*prototypes for functions*/
/*--------------------------------------------------------------------*/
void addition()
{
float a,b;
cout<<"\naddition() called :";
cout<<"\nenter the first number :";
cin>>a;
cout<<"\nenter the second number :";
cin>>b;
cout<<"\naddition of numbers = "<<a+b;
}
/*-----------------------------------------------------------------------*/
void subtraction()
{
float a,b;
cout<<"\nsubtraction() called :";
cout<<"\nenter the first number :";
cin>>a;
cout<<"\nenter the second number :";
cin>>b;
cout<<"\nsubtraction of numbers ="<<a-b;
}
/*------------------------------------------------------------------------*/
void multiplication()
{
float a,b;
cout<<"\nmultiplication() called :";
cout<<"\nenter the first number :";
cin>>a;
cout<<"\nenter the second number :";
cin>>b;
cout<<"\multiplication of numbers ="<<a*b;
}
/*-------------------------------------------------------------------------*/
void division()
{
float a,b;
cout<<"\ndivision() called :";
cout<<"\nenter the first number :";
cin>>a;
cout<<"\nenter the second number :";
cin>>b;
cout<<"\ndivision  of numbers ="<<a/b;
}
/*-----------------------------------------------------------------------*/
void power()
{
double a,b;
cout<<"\npower() called";
cout<<"\nenter the base :";
cin>>a;
cout<<"enter the power :";
cin>>b;
cout<<"\n"<<a<<" ^ "<<b<<" = "<<pow(a,b);
}
/*------------------------------------------------------------------------*/
void sqrroot()
{
double x;
cout<<"\nsqrroot() called :";
cout<<"\nenter the number whose square root is to be find out : ";
cin>>x;
cout<<"\nthe square-root of "<<x<<" is "<<sqrt(x);
}
/*----------------------------------------------------------------------*/
void log_e()
{
double x;
cout<<"\nlog_e() called :";
cout<<"\nenter the  number whose logrithm is to be calculated :";
cin>>x;
cout<<"\nthe log of "<<x<<" to the base 'e' is "<<log(x);
}

void log_10()
{
double x;
cout<<"\nlog_10() called :";
cout<<"\nenter the number whose logrithm is to be calculated :";
cin>>x;
cout<<"\nthe log of "<<x<<" to the base '10' is "<<log10(x);
}
/*-----------------------------------------------------------------------*/
void polynomial()
 {

int i;
double d,x;
double array[10];
puts("\npolynomial() called :");

puts("\nenter the degree of the polynomial :");
scanf("%lf",&d);
puts("\enter the coeffecients of poly starting from degree 0:");
for( i=0;i<=d;i++)
cin>>array[i];
puts("\nthe entered poly is \n:");
for( i=0;i<=d;i++)
printf("%lf x ^ %d + ",array[i],i);
puts("\nenter the value of 'x' at which poly is to be calculated :");
scanf("%lf",&x);
printf("The result of poly is %lf:",poly(x,d,array));
}
/*----------------------------------------------------------------------*/
void cosine()
{
double d,x;
puts("\ncosine() called :");
puts("\nenter the angle in degrees ");
scanf("%lf",&d);
x=(3.14) *(d/180);
printf("The value of cos( %lf ) is %lf",d,cos(x) );
}

void sine()
{
double d,x;
puts("\nsine() called :");
puts("\nenter the angle in degrees ");
scanf("%lf",&d);
x=(3.14) *(d/180);
printf("The value of sin( %lf ) is %lf",d,sin(x) );
}

void tangent()
{
double d,x;
puts("\ntangent() called :");
puts("\nenter the angle in degrees ");
scanf("%lf",&d);
x=(3.14) *(d/180);
printf("The value of tan( %lf ) is %lf",d,tan(x) );
}
/*---------------------------------------------------------------------*/
void cos_inv()
{
  double x,d;
  puts("\ncos_inv() called :");
  puts("\nenter the value of arg :");
  scanf("%lf",&x);
  d=acos(x)*(180/3.14);
  printf("The value of cos^-1(%lf) is %lf",x,d );
}


void sin_inv()
{
  double x,d;
  puts("\nsin_inv() called :");
  puts("\nenter the value of arg :");
  scanf("%lf",&x);
  d=asin(x)*(180/3.14);
  printf("The value of sin^-1(%lf) is %lf",x,d );
}

void tan_inv()
{
  double x,d;
  puts("\ntan_inv() called :");
  puts("\nenter the value of arg :");
  scanf("%lf",&x);
  d=atan(x)*(180/3.14);
  printf("The value of tan^-1(%lf) is %lf",x,d );
}
/*----------------------------------------------------------------------*/
void menu()
{
int i;
char choice;
cout<<"\n=================MENU=================";
cout<<"\n\n1 : addition  :\t\t11: sine    : ";
cout<<"\n\n2 : subtract  :\t\t12: tangent :";
cout<<"\n\n3 : multiply  :\t\t13: cos_inv :";
cout<<"\n\n4 : division  :\t\t14: sin_inv :";
cout<<"\n\n5 : power     :\t\t15: tan_inv :";
cout<<"\n\n6 : sqrroot   :\t\t16: exit    :";
cout<<"\n\n7 : log_e     :";
cout<<"\n\n8 : log_10    :";
cout<<"\n\n9 : polynomial:";
cout<<"\n\n10: cosine    :";
cout<<"\n=======================================";

cout<<"\n\nenter a choice from menu (1 - 16):";
cin>>i;
if(i<=0||i>16)
{
cout<<"\nYou entered an invalid option , ";
cout<<"Try again....";
menu();
}

switch(i)
{
case 1 : addition();
break;
case 2 : subtraction();
break;
case 3 : multiplication();
break;
case 4 : division();
break;
case 5 : power();
break;
case 6 : sqrroot();
break;
case 7 : log_e();
break;
case 8 :log_10();
break;
case 9 :polynomial();
break;
case 10 :cosine();
break;
case 11 :sine();
break;
case 12 :tangent();
break;
case 13 :cos_inv();
break;
case 14 :sin_inv();
break;
case 15 :tan_inv();
break;
case 16 :
return;
}
cout<<"\n\nstill want to continue (y or n) :";
cin>>choice;
if(choice=='y')
menu();
if(choice=='n')
{
return;
}
}
/*graphics for the front page */
void graphics1()
{
int driver=DETECT,mode;
int errorcode;
initgraph(&driver,&mode,"c:\\turboc3\\bin");
errorcode=graphresult();
if(errorcode!=grOk)
{
cout<<"\nError opening the graphics mode :";
cout<<"\nPress any key to halt :";
getch();
exit(1);
}

setbkcolor(2);
setcolor(4);
settextstyle(10,HORIZ_DIR,4);
outtextxy(150,20,"CALCULATOR");
delay(3000);
settextstyle(10,HORIZ_DIR,2);
outtextxy(150,150,"Prepared by Harshit");
settextstyle(2,HORIZ_DIR,4);
outtextxy(250,300,"please wait....");
delay(6000);
settextstyle(2,HORIZ_DIR,4);
outtextxy(10,400,"Press enter to continue :");
getch();
closegraph();
}
/*graphics for the last page */
void graphics2()
{
int driver=DETECT,mode;
int errorcode;
initgraph(&driver,&mode,"c:\\turboc3\\bin");
errorcode=graphresult();
if(errorcode!=grOk)
{
cout<<"\nError opening the graphics mode :";
cout<<"\nPress any key to halt :";
getch();
exit(1);
}
setbkcolor(6);
setcolor(3);
settextstyle(10,HORIZ_DIR,4);
outtextxy(150,150,"Thank You !");
getch();
closegraph();
}





/*-----------------------------------------------------------------*/
void main()
{
clrscr();
graphics1();
menu();
graphics2();
getch();
}




