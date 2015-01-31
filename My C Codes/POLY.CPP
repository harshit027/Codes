/*storing a polynomial and operations on it : HARSHIT*/
#include"stdio.h"
#include"conio.h"
#include"stdlib.h"


typedef struct polynomial
{
int coef,pow;
struct polynomial *next;
}poly;
poly *first,*first1,*ttemp,*temp,*temp1,*temp2,*l1first,*l2first,*last,*between,*beforefirst;

/*----------------------------------------------------------------*/
/*all the declared pointers set to NULL*/
void setnull()
{
first=first1=temp=temp1=temp2=l1first=l2first=last=between=beforefirst=NULL;
}
/*----------------------------------------------------------------*/
/*creates the list to  store the polynomial :*/
void createpoly(int c, int p)
{
puts("\nenter the value of coeffecient :");
scanf("%d",&c);
puts("\nenter the value of power :");
scanf("%d",&p);
if (first==NULL)
{
first=(poly*)malloc(sizeof(poly));
first->coef=c;
first->pow=p;
first->next=NULL;
}
else
{
temp=first;
while(temp->pow>p && temp->next!=NULL)
{
ttemp=temp;
temp=temp->next;
}
if(temp->pow>p && temp->next==NULL)
{
last=(poly*)malloc(sizeof(poly));
last->coef=c;
last->pow=p;
last->next=NULL;
temp->next=last;
}
else
{
if(temp ==first && temp->pow<p)
{
beforefirst=(poly*)malloc(sizeof(poly));
beforefirst->pow=p;
beforefirst->coef=c;
beforefirst->next=first;
first=beforefirst;
}
else
if(ttemp->pow>p && temp->pow<p)
{
between=(poly*)malloc(sizeof(poly));
between->pow=p;
between->coef=c;
ttemp->next=between;
between->next=temp;
}
else
temp->coef=temp->coef+c;
}}}


/*-----------------------------------------------------------------*/
/*finds the result of the addition of nodes*/
void result(int c, int p)
{


if (first==NULL)
{
first=(poly*)malloc(sizeof(poly));
first->coef=c;
first->pow=p;
first->next=NULL;
}
else
{
temp=first;
while(temp->pow>p && temp->next!=NULL)
{
ttemp=temp;
temp=temp->next;
}
if(temp->pow>p && temp->next==NULL)
{
last=(poly*)malloc(sizeof(poly));
last->coef=c;
last->pow=p;
last->next=NULL;
temp->next=last;
}
else
{
if(temp ==first && temp->pow<p)
{
beforefirst=(poly*)malloc(sizeof(poly));
beforefirst->pow=p;
beforefirst->coef=c;
beforefirst->next=first;
first=beforefirst;
}
else
if(ttemp->pow>p && temp->pow<p)
{
between=(poly*)malloc(sizeof(poly));
between->pow=p;
between->coef=c;
ttemp->next=between;
between->next=temp;
}
else
temp->coef=temp->coef+c;
}}}




/*-------------------------------------------------------------------*/
/*insertion of two polynomials*/
/*insertion of 1st polynomial*/
void start1()
{
puts("\list 1 is created to store the polnomial:");
}
void display1()
{
temp=l1first;
puts("\nthe 1st polynomial you entered is :");
while(temp!=NULL)
{
printf("%d x^%d +",temp->coef,temp->pow);
temp=temp->next;
}}
void createpoly1(int c, int p)
{
puts("\nenter the value of coeffecient :");
scanf("%d",&c);
puts("\nenter the value of power :");
scanf("%d",&p);
if (l1first==NULL)
{
l1first=(poly*)malloc(sizeof(poly));
l1first->coef=c;
l1first->pow=p;
l1first->next=NULL;
}
else
{
temp=l1first;
while(temp->pow>p && temp->next!=NULL)
{
ttemp=temp;
temp=temp->next;
}
if(temp->pow>p && temp->next==NULL)
{
last=(poly*)malloc(sizeof(poly));
last->coef=c;
last->pow=p;
last->next=NULL;
temp->next=last;
}
else
{
if(temp ==l1first && temp->pow<p)
{
beforefirst=(poly*)malloc(sizeof(poly));
beforefirst->pow=p;
beforefirst->coef=c;
beforefirst->next=l1first;
l1first=beforefirst;
}
else
if(ttemp->pow>p && temp->pow<p)
{
between=(poly*)malloc(sizeof(poly));
between->pow=p;
between->coef=c;
ttemp->next=between;
between->next=temp;
}
else
temp->coef=temp->coef+c;
}}}


/*insertion of 2nd polynomial*/
void start2()
{
puts("\nlist 2 is created to store the polynomials:");
}
void display2()
{
temp=l2first;
puts("\nthe 2nd polynomial entered is :");
while(temp!=NULL)
{
printf("%d x^%d +",temp->coef,temp->pow);
temp=temp->next;
}}
void createpoly2(int c, int p)
{
puts("\nenter the value of coeffecient :");
scanf("%d",&c);
puts("\nenter the value of power :");
scanf("%d",&p);
if (l2first==NULL)
{
l2first=(poly*)malloc(sizeof(poly));
l2first->coef=c;
l2first->pow=p;
l2first->next=NULL;
}
else
{
temp=l2first;
while(temp->pow>p && temp->next!=NULL)
{
ttemp=temp;
temp=temp->next;
}
if(temp->pow>p && temp->next==NULL)
{
last=(poly*)malloc(sizeof(poly));
last->coef=c;
last->pow=p;
last->next=NULL;
temp->next=last;
}
else
{
if(temp ==l2first && temp->pow<p)
{
beforefirst=(poly*)malloc(sizeof(poly));
beforefirst->pow=p;
beforefirst->coef=c;
beforefirst->next=l2first;
l2first=beforefirst;
}
else
if(ttemp->pow>p && temp->pow<p)
{
between=(poly*)malloc(sizeof(poly));
between->pow=p;
between->coef=c;
ttemp->next=between;
between->next=temp;
}
else
temp->coef=temp->coef+c;
}}}



/*---------------------------------------------------------------------*/
/*addition of two polynomials*/
void addpoly()
{
int p;
temp1=l1first;
temp2=l2first;
while(temp1!=NULL&&temp2!=NULL)
{
if(temp1->pow>temp2->pow)
{
result(temp1->coef,temp1->pow);
temp1=temp1->next;
}
else if(temp2->pow>temp1->pow)
{
result(temp2->coef,temp2->pow);
temp2=temp2->next;
}
else
{
if(temp1->pow==temp2->pow)
p=temp1->coef+temp2->coef;
result(p,temp1->pow);
temp1=temp1->next;
temp2=temp2->next;
}}
if(temp1==NULL)
{
while(temp2!=NULL)
{
result(temp2->coef,temp2->pow);
temp2=temp2->next;
}}
else
while(temp1!=NULL)
{
result(temp1->coef,temp1->pow);
temp1=temp1->next;
}
puts("\nthe sum of two polynomials = ");
}

/*---------------------------------------------------------------------*/
/*multiplication of polynomials*/
void multiply()
{
int c=0,p=0;
temp1=l1first;
while(temp1!=NULL)
{
temp2=l2first;
while(temp2!=NULL)
{
c=temp1->coef*temp2->coef;
p=temp1->pow+temp2->pow;
result(c,p);
temp2=temp2->next;
}
temp1=temp1->next;
}
puts("\nthe multiplication of the polynomials is :");
}


/*-------------------------------------------------------------------*/
/*power function */

int power(int x,int y)
{
int z=1,i;
for(i=1;i<=y;i++)
z=z*x;
return z;
}

/*evaluates the value of poly for entered variable*/
void evaluate()
{
int x,result=0;
puts("\nenter the value of x");
scanf("%d",&x);
temp=l1first;
while(temp!=NULL)
{
result=result+(temp->coef*(power(x,temp->pow)));
temp=temp->next;
}
printf("\nthe result of polynomial is = %d",result);
}



/*-----------------------------------------------------------------*/
/*displays the list */
void display ()
{
puts("\nthe entered polynomial is :\n");
temp=first;
while(temp!=NULL)
{
printf("%d x^%d + ",temp->coef,temp->pow);
temp=temp->next;
}}


/*---------------------------------------------------------------------*/

void main()
{
int p,c;
clrscr();
setnull();
start1();
createpoly1(c,p);
createpoly1(c,p);
display1();
start2();
createpoly2(c,p);
createpoly2(c,p);
display2();
addpoly();
display();

getch();
}
