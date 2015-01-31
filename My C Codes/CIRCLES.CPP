/*plotting circle using cartesian equation : HARSHIT*/

#include"header.h"


int xcc,ycc;
int y,x,xc,yc,r;

void plotcircle()
{
for(x=xc+r;x>=xc;x--)
{
delay(50);
y=yc-sqrt((r*r)-(pow((x-xc),2)));
putpixel(xcc+x,ycc-y,4);
y=yc+sqrt((r*r)-(pow((x-xc),2)));
putpixel(xcc+x,ycc-y,4);
}
for(x=xc-r;x<=xc;x++)
{
delay(50);
y=yc-sqrt((r*r)-(pow((x-xc),2)));
putpixel(xcc+x,ycc-y,4);
y=yc+sqrt((r*r)-(pow((x-xc),2)));
putpixel(xcc+x,ycc-y,4);
}
}


void main()
{
int driver,mode;
int errorcode;
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
cout<<"\nenter the radius of circle ( <=180 ) :";
cin>>r;
cleardevice();
xcc=getmaxx()/2;
ycc=getmaxy()/2;
setcolor(getmaxcolor());
line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
line(getmaxx()/2,0,getmaxx()/2,getmaxy());
outtextxy(10,10,"By cartesian equation of circle");
line(10,20,260,20);
outtextxy(xcc+xc-20,ycc-yc+10,"(xc,yc)");
plotcircle();
getch();
closegraph();
}









