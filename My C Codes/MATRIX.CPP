/*prints the matrix whose elements are entered :HARSHIT*/
#include"iostream.h"
#include"conio.h"
void main()
{
clrscr();
int a[10][10],i,j,r,c;
cout<<"\nenter the number of rows and coloumns";
cin>>r>>c;
cout<<"\nrows="<<r<<"\ncoloums="<<c;
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
cin>>a[i][j];
}
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
cout<<a[i][j]<<"      ";
cout<<"\n";
}
getch();
}

