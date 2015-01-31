/*prints the first 'n' prime numbers : HARSHIT*/


#include<iostream.h>
#include<conio.h>
//#include<process.h>

void main()
{
clrscr();
int a,k,i,j,n;
cout<<"\nenter the number of elements to be displayed :";
cin>>n;
cout<<"the first "<<n<<" prime numbers are ...";
a=2;
for(j=0;j<n;j++)
{
k=0;
if(a==2)
k=0;

else
{
for(i=2;i<a;i++)
{
if(a%i==0)
{
a++;
i=2;
}

else
k=0;

}
}
if(k==0)
cout<<"\n"<<a;
a++;

}
getch();
}
