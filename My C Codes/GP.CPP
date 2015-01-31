/*prints the gp series:HARSHIT*/
#include"iostream.h"
#include"conio.h"
#include"math.h"
void main()
{
clrscr();
int a,c=0,i,n;
cout<<"\nenter the number of terms of GP series : ";
cin>>n;
cout<<"\nenter common ratio : ";
cin>>a;
for(i=0;i<=n;i+=1)
{
c=pow(a,i);
cout<<c<<"\n";
}
getch();
}




