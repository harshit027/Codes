/*pre-processor directives :HARSHIT*/
						      /*include*/
#include"iostream.h"
#include"conio.h"
						      /*define*/
#define big 5
#define small 6
						     /*stringizing*/
#define writestring(x) cout<<#x

void main()
{
clrscr();                                             /*ifdef*/
#ifdef big
cout<<"\nbig is defined !";                           /*else*/
#else
cout<<"\nbig not defined !";                          /*endif*/
#endif
						      /*ifndef*/
#ifndef small
cout<<"\nsmall not defined !";
#else
cout<<"\nsmall defined !";
#endif

#ifndef medium
cout<<"\nmedium not defined !";
#else
cout<<"\nmedium defined !";
#endif
						       /*undef*/
#undef big

#ifdef big
cout<<"\nbig is defined !";
#else
cout<<"\nbig not defined !\n";
#endif

writestring(This is my string !);
getch();
}