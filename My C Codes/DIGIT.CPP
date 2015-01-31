 /*calculates sum of digits entered by user :HARSHIT*/
 #include"iostream.h"
 #include"conio.h"
 void main()
 {
 clrscr();
 int n,i,a,s=0;
 cout<<"\nenter the number of digits = ";
 cin>>n;
 cout<<"\nenter the number\n";
 for(i=1;i<=n;i++)
 {
 cin>>a;
 s=s+a;
 }
 cout<<"\nthe sum of digits is = "<<s;
 getch();
 }


