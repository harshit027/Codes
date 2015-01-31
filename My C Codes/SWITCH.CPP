/*a simple calculator : HARSHIT*/

#include"iostream.h"
#include"conio.h"
#include"math.h"
void calculate()
{
float a,b;
char choice,bin;
cout<<"\n===========MENU===========";
cout<<"\naddition:";
cout<<"\nsubtraction:";
cout<<"\ndivision:";
cout<<"\nmultiplication:";
cout<<"\npower:";
cout<<"\nexit:";
cout<<"\n==========================";
cout<<"\n\nwhat you what you want to do (a,s,d,m,p,e):";
cin>>choice;
switch(choice)
{
case 'a':
{
cout<<"\nenter 'a' and 'b' : ";
cin>>a>>b;
cout<<"\n"<<a<<" + "<<b<<" = "<<a+b;
break;
}
case 's':
{
cout<<"\nenter 'a' and 'b' : ";
cin>>a>>b;
cout<<"\n"<<a<<" - "<<b<<" = "<<a-b;
break;
}
case 'd':
{
cout<<"\nenter 'a' and 'b' : ";
cin>>a>>b;
cout<<"\n"<<a<<" / "<<b<<" = "<<a/b;
break;
}
case 'm':
{
cout<<"\nenter 'a' and 'b' : ";
cin>>a>>b;
cout<<"\n"<<a<<" * "<<b<<" = "<<a*b;
break;
}
case 'p':
{
cout<<"\nenter 'a' and 'b' : ";
cin>>a>>b;
cout<<"\n"<<a<<" ^ "<<b<<" = "<<pow(a,b);
break;
}
case 'e':
{
cout<<"\nThank you !";
return;
}
}
cout<<"\nwant to continue ? (y or n) : ";
cin>>bin;
if(bin=='y')
{
calculate();
}
else
{
cout<<"\nThank you !";
return ;
}
getch();
}

void main()
{
clrscr();
calculate();
}
