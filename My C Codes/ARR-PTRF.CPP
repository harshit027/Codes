/*array of pointer to functions :HARSHIT */

#include"header.h"

void square(int a,int b)
{
cout<<"\square() called :";
cout<<"\nenter the value :";
cin>>a;
b=a*a;
cout<<"\nthe square of number is :"<<b;
}

void cube(int a,int b)
{
cout<<"\ncube() called :";
cout<<"\nenter the value :";
cin>>a;
b=a*a*a;
cout<<"\nthe cube of the number is :"<<b;
}

void sum(int a,int b)
{
cout<<"\nsum() called :";
cout<<"\nenter the values :";
cin>>a>>b;
a=a+b;
cout<<"\nthe addition is : "<<a;
}

void minus(int a,int b)
{
cout<<"\nminus() called :";
cout<<"\nenter the values :";
cin>>a>>b;
a=a-b;
cout<<"\nthe difference is : "<<a;
}

void product(int a,int b)
{
cout<<"\nproduct() called :";
cout<<"\nenter the values :";
cin>>a>>b;
a=a*b;
cout<<"\nthe product is : "<<a;
}

void main()
{
clrscr();
int i,a,b;
const int size=5;
void (*p[size]) (int ,int);
p[0]=square;
p[1]=cube;
p[2]=sum;
p[3]=minus;
p[4]=product;

for(i=0;i<size;i++)
p[i](a,b);
getch();
}
