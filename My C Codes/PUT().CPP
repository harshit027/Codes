/*cout.put('char') , cout.write(char *,int) :HARSHIT*/

#include"iostream.h"
#include"conio.h"
#include"string.h"

void main()
{
clrscr();
char s[]="party days are back";
int len=strlen(s);
cout<<"\ncharacters written using cout.put()\n";
cout.put('H').put('e').put('l').put('l').put('o');

cout<<"\ncharacters written using cout.write()\n";
cout.write(s,len)<<endl;

getch();
}