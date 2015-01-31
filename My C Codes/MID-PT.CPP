/*plotting circle using mid-pt circle algorithm : HARSHIT*/

#include"header.h"

int xc,yc,x,y,r;
int xcc,ycc;

void plotpixel()
{
putpixel(xcc+xc+x,ycc-yc+y,4);
putpixel(xcc+xc-x,ycc-yc+y,4);
putpixel(xcc+xc+x,ycc-yc-y,4);
putpixel(xcc+xc-x,ycc-yc-y,4);
putpixel(xcc+xc+y,ycc-yc+x,4);
putpixel(xcc+xc-y,ycc-yc+x,4);
putpixel(xcc+xc+y,ycc-yc-x,4);
putpixel(xcc+xc-y,ycc-yc-x,4);
}
void main()
{
int driver,mode;
int errorcode;
int p0,p;
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
cout<<"\nenter the 'x' coordinate of center :";
cin>>xc;
cout<<"\nenter the 'y' coordinate of center :";
cin>>yc;
cout<<"\nenter the radius of circle :";
cin>>r;
cleardevice();
xcc=getmaxx()/2;
ycc=getmaxy()/2;
x=0;
y=r;
p0=1-r;
p=p0;
line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
line(getmaxx()/2,0,getmaxx()/2,getmaxy());
outtextxy(10,10,"By Mid-point circle algorithm");
line(10,20,250,20);
outtextxy(xcc+xc-20,ycc-yc+10,"(xc,yc)");
while(x<y)
{
if(p<0)
{
x=x+1;
delay(50);
plotpixel();
p=p+(2*x)+1;
}
else
{
x=x+1;
y=y-1;
delay(50);
plotpixel();
p=p+(2*x)+1-(2*y);
}}
getch();
closegraph();
}





