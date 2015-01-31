/*passing array to a function with one parameter :HARSHIT*/
#include"iostream.h"
#include"conio.h"
#define max 20
int i;
int largest(int a[]);
void main()
{
clrscr();
int array[max];
cout<<"\nenter the elements of array ,0 to exit(<20): \n";
for(i=0;i<max;i++)
{
cin>>array[i];
if(array[i]==0)
i=max;
}
array[max]=0;
cout<<"\nthe largest number entered is "<<largest(array);
getch();
}
int largest(int a[])
{
int biggest=0;
for(i=0;a[i]!=0;i++)
{
if(a[i]>biggest)
biggest=a[i];
}
return biggest;
}