/*calculates the sum and avg of numbers entered by user:HARSHIT*/
#include"iostream.h"
#include"conio.h"
void main()
{
clrscr();
int i,n,num[50];
float sum=0;
cout<<"\nenter number of terms : ";
cin>>n;
cout<<"\nenter the numbers : ";
for(i=1;i<=n;i++)
{
cin>>num[i];
sum=sum+num[i];
}
cout<<"\nsum of numbers is : "<<sum;
cout<<"\naverage of numbers is : "<<(sum/n);
getch();
}