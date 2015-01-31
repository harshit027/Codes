 /*demonstration of array :HARSHIT */
 #include"iostream.h"
 #include"conio.h"
 void main()
 {
 clrscr();
 int i,n,rollno[90];
 cout<<"\nenter the number of roll numbers to be stored : ";
 cin>>n;
 for(i=0;i<n;i++)
 {
 cout<<"\nenter the rollno : ";
 cin>>rollno[i];
 cout<<"u have entered:"<<rollno[i];
 }
 getch();
 }
