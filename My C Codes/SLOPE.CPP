/*plotting line using equation of line :HARSHIT*/
#include"iostream.h"
#include"conio.h"
#include"graphics.h"
#include"process.h"
#include"dos.h"
void main()
{
int driver,mode;
int errorcode;
int x1,x2,y1,y2,c;
float m;
int i,y;
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
cout<<"\nenter the value of intercept :";
cin>>c;
int xc,yc;
xc=getmaxx()/2;
yc=getmaxy()/2;

cleardevice();
m=(y2-y1)/(x2-x1);
setcolor(getmaxcolor());
line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
line(getmaxx()/2,0,getmaxx()/2,getmaxy());
for(i=x1;i<=x2;i++)
{
y=(m*i)+c;
delay(50);
putpixel(xc+i,yc-y,4);
}
getch();
closegraph();
}
