/*time and date :HARSHIT*/

#include"iostream.h"
#include"time.h"
#include"conio.h"

void main()
{
clrscr();
time_t currenttime;

time(&currenttime);
cout<<"\nit is now "<<ctime(&currenttime);

tm *ptm = localtime(&currenttime);
cout<<"\ntoday is \n"<<ptm->tm_mon<<" \ "<<ptm->tm_mday<<" \ "<<ptm->tm_year;
getch();
}