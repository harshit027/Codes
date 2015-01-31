/*moving circle : HARSHIT*/

#include"iostream.h"
#include"conio.h"
#include"graphics.h"
#include"dos.h"

int xc,yc,i,j;

void drawline()
{
line(0,yc,xc,0);
line(xc,0,getmaxy(),yc);
line(getmaxy(),yc,xc,getmaxy());
line(xc,getmaxy(),0,yc);
}

void movecircle()
{
char c;
for(i=0,j=yc;i<=xc&&j>=0;i++,j--)
{
cleardevice();
setcolor(15);
drawline();
setcolor(4);
circle(i,j,20);
delay(20);
}
for(i=xc,j=0;i<=getmaxy()&&j<=yc;i++,j++)
{
cleardevice();
setcolor(15);
drawline();
setcolor(4);
circle(i,j,20);
delay(20);
}
for(i=getmaxy(),j=yc;i>=xc&&j<=getmaxy();i--,j++)
{
cleardevice();
setcolor(15);
drawline();
setcolor(4);
circle(i,j,20);
delay(20);
}
for(i=xc,j=getmaxy();i>=0&&j>=yc;i--,j--)
{
cleardevice();
setcolor(15);
drawline();
setcolor(4);
circle(i,j,20);
delay(20);
}
cout<<"\nsee again (y/n) ? ";
cin>>c;
if(c=='y')
movecircle();
else
return;
}
void main()
{
clrscr();
int driver,mode;
driver=DETECT;
initgraph(&driver,&mode,"");
xc=getmaxy()/2;
yc=getmaxy()/2;
setcolor(4);
movecircle();
getch();
closegraph();
}
