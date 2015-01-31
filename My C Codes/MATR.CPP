/*calculates sum of two matrices : HARSHIT*/
#include"iostream.h"
#include"conio.h"
void main()
{
clrscr();
int a[10][10],i,j,r1,c1,r2,c2,b[10][10],c[10][10];
cout<<"\nenter the number of rows and coloumns : ";
cin>>r1>>r2>>c1>>c2;
cout<<"\nrows of matrix:1="<<r1<<"\ncoloumns of matrix:1="<<c2;
cout<<"\nrows of matrix:2="<<r2<<"\ncoloumns of matrix:2="<<c2;
if(r1==r2&&c1==c2)
{
cout<<"\nenter the elements of matrix 1 : ";
for(i=0;i<r1;i++)
{
for(j=0;j<c1;j++)
cin>>a[i][j];
}
cout<<"\nthe 1st array you entered is : \n";
for(i=0;i<r1;i++)
{
for(j=0;j<c2;j++)
cout<<a[i][j]<<"\t";
cout<<"\n";
}
cout<<"\nenter the elements of matrix 2 : ";
for(i=0;i<r2;i++)
{
for(j=0;j<c2;j++)
cin>>b[i][j];
}
cout<<"\nthe 2nd array you entered is : \n";
for(i=0;i<r2;i++)
{
for(j=0;j<c2;j++)
cout<<b[i][j]<<"\t";
cout<<"\n";
}
cout<<"\nsum of matrices = "<<"\n";
for(i=0;i<r1;i++)
{
for(j=0;j<c1;j++)
c[i][j]=a[i][j]+b[i][j];
}
for(i=0;i<r2;i++)
{
for(j=0;j<c2;j++)
cout<<c[i][j]<<"\t";
cout<<"\n";
}
}
else
cout<<"\n addition cannot be done";
getch();
}





