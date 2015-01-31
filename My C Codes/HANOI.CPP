/*solution to tower of hanoi:HARSHIT*/
#include"iostream.h"
#include"conio.h"

void hanoi(int n,char from,char to,char inter)
{
if(n==1)
{
cout<<"\n\nmove disk 1 from "<<from<<" to "<<to;
return;
}
hanoi(n-1,from,inter,to);
cout<<"\n\nmove disk "<<n<<" from "<< from<<" to "<<to;
hanoi(n-1,inter,to,from);
}

void main()
{
clrscr();
int n;
char from,to,inter;
cout<<"\nenter the number of towers:";
cin>>n;
cout<<"\nenter name of towers ";
cin>>from>>inter>>to;
cout<<"\nthe disks can be transferred from "<<from<<" to "<<to<<" as :";
hanoi(n,from,to,inter);
getch();
}
