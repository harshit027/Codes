/*using command line arguments :HARSHIT*/
/*to see it working type "c:\BIN\COMM-LIN teach yourself c++ " in command prompt*/
#include"iostream.h"
#include"conio.h"

void main(int argc,char ** argv)
{
clrscr();

cout<<"\nrecieved "<<argc<<" arguments";
for(int i=0;i<argc;i++)
{
cout<<"\nargument "<<i<<" : "<<argv[i];
}
getch();
}

