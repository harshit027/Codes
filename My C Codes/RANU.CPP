/*calculates sum of natural numbers :HARSHIT */
#include"iostream.h"
#include"conio.h"
void main()
{
clrscr();
int sum=0,i,n;
cout<<"\nenter number of elements : ";
cin>>n;
for(i=1;i<=n;i+=1)
{
cout<<i<<"  ";
sum=sum+i;
}
cout<<"\nsum="<<sum;
getch();
}