/*plotting line using DDA algorithm :HARSHIT*/
#include"iostream.h"
#include"conio.h"
#include"graphics.h"
#include"process.h"
#include"dos.h"
void main()
{
int driver,mode;
int errorcode;
int x1,x2,y1,y2,dx,dy,step;
float x_incr,y_incr;
int i,xk,yk,x,y;
int xc,yc;
driver=DETECT;
initgraph(&driver,&mode,"c:\\tc\\bin");
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
if(x2>x1&&y2>y1)
{
dx=x2-x1;
dy=y2-y1;
}
else
{
dx=x1-x2;
dy=y1-y2;
}
if(dx>dy)
step=dx;
else
step=dy;
xc=getmaxx()/2;
yc=getmaxy()/2;

x_incr=dx/step;
y_incr=dy/step;
x=x1;
y=y1;
setcolor(getmaxcolor());
putpixel(x,y,4);
line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
line(getmaxx()/2,0,getmaxx()/2,getmaxy());
for(i=1;i<=step;i++)
{
yk=y+y_incr;
xk=x+x_incr;
delay(50);
putpixel(xc+xk,yc-yk,4);
y=yk;
x=xk;
}
getch();
closegraph();
}


