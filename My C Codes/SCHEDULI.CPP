/*CPU scheduling :HARSHIT */

#include"iostream.h"
#include"conio.h"


void main()
{
clrscr();
int p[20],i,t[20],wt,ta;
ta=wt=0;
float avgwt,avgta;
avgta=avgwt=0;
cout<<"\nenter the number of process in scheduler :";
cin>>i;
for(int j=0;j<i;j++)
{
cout<<"\nenter the CPU Bus time for the process p"<<j<<":";
cin>>t[j];
}
for(j=0;j<i-1;j++)
wt=wt+t[j];
for(j=0;j<i;j++)
ta=ta+t[j];
avgwt=wt/i;
avgta=ta/i;
cout<<"\n\nprocess"<<"     Bus time";
for(j=0;j<i;j++)
cout<<"\np"<<j<<"		"<<t[j];
cout<<"\n\naverage waiting time = "<<avgwt;
cout<<"\naverage turn around time = "<<avgta;
getch();
}