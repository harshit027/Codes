/*drawing line using bresenham's algorithm*/

#include"iostream.h"
#include"conio.h"
#include"process.h"
#include"graphics.h"
#include"dos.h"
void main()
{
int errorcode,driver,mode;
int x1,x2,y1,y2,xk,yk,xkk,ykk,temp;
int dx,dy;
int p1,pk,pkk;
int xc,yc;
driver=DETECT;
initgraph(&driver,&mode,"c:\\tc\\bgi");
errorcode=graphresult();
if(errorcode!=grOk)
{
cout<<"\nerror opening the graphics mode :";
cout<<"\npress any key to halt :";
getch();
exit(1);
}
cout<<"\nenter the value of x1 coordinate :";
cin>>x1;
cout<<"\nenter the value of x2 coordinate :";
cin>>x2;
cout<<"\nenter the value of y1 coordinate :";
cin>>y1;
cout<<"\nenter the value of y2 coordinate :";
cin>>y2;
cleardevice();

dy=y2-y1;
dx=x2-x1;

if(dy>dx)
{
temp=dy;
dy=dx;
dx=temp;
}


p1=(2*dy)-dx;
pk=p1;
xk=x1;
yk=y1;
xc=getmaxx()/2;
yc=getmaxy()/2;
setcolor(getmaxcolor());
line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
line(getmaxx()/2,0,getmaxx()/2,getmaxy());
outtextxy(10,10,"By Bresenham's algorithm");
line(10,20,210,20);
putpixel(x1,y1,4);

for(int k=0;k<=dx;k++)
{
if(pk<0)
{
xkk=xk+1;
ykk=yk;
delay(50);
putpixel(xc+xkk,yc-ykk,4);
xk=xkk;
yk=ykk;
pkk=pk+(2*dy);
pk=pkk;
}
else
if(pk>=0)
{
xkk=xk+1;
ykk=yk+1;
delay(50);
putpixel(xc+xkk,yc-ykk,4);
xk=xkk;
yk=ykk;
pkk=pk+((2*dy)-dx);
pk=pkk;
}}
getch();
closegraph();
}