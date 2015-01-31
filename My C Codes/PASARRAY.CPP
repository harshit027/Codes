/*passing array to a function with two parameters, larjest number:HARSHIT*/
#include"iostream.h"
#include"conio.h"

typedef int twodim[10][10];

void aggregate(twodim table,int row,int col)
{
int i,j,sum=0;
cout<<"\nthe table you entered is :\n\n";
for(i=0;i<row;i++)
{
for(j=0;j<col;j++)
cout<<table[i][j]<<"\t";
cout<<"\n";
}
cout<<"\n------------------------\n";
for(j=0;j<col;j++)
{
for(i=0;i<row;i++)
sum=sum+table[i][j];
cout<<sum<<"\t";
sum=0;
}
cout<<"total";
}

int largest(int a[],int b)
{
int i, biggest=0;
for(i=0;i<b;i++)
{
if(a[i]>biggest)
biggest=a[i];
}
return biggest;
}


void main()
{
clrscr();
int i,a[20],n,r,c;
twodim table;
cout<<"\npassing 1-D array as parameter !";
cout<<"\nenter the size of array (<20):";
cin>>n;
cout<<"\nenter the elements of array : ";
for(i=0;i<n;i++)
cin>>a[i];
cout<<"\nthe largest of all entered values is "<<largest(a,n);
cout<<"\n-------------------------------------------------------";
cout<<"\n\npassing 2-D array as parameter !";
cout<<"\nenter the dimension of 2-D array (row*col):";
cin>>r>>c;
cout<<"\nenter the elements of 2-D array :";
for(i=0;i<r;i++)
{
for(int j=0;j<c;j++)
cin>>table[i][j];
}
aggregate(table,r,c);
getch();
}


