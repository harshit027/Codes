/*returning multiple statements using pointers :HARSHIT */
#include"iostream.h"
#include"conio.h"

int factor(int n,int *psqr,int *pcube)
{
int value=0;
if(n>20)
value=1;
else
{
*psqr=n*n;
*pcube=n*n*n;
}
return value;
}
void main()
{
clrscr();
int n,sqr,cube;
int error;
cout<<"enter any number (int) :";
cin>>n;
error=factor(n,&sqr,&cube);
if(!error)
{
cout<<"\nnumber = "<<n;
cout<<"\nsquare = "<<sqr;
cout<<"\ncube = "<<cube;
}
else
cout<<"\nerror encountered :";
getch();
}