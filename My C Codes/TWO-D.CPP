/*2-D primitive transformations :HARSHIT*/


#include"iostream.h"
#include"conio.h"
#include"graphics.h"
#include"math.h"

int xcc,ycc;

void figure(int x1,int x2,int x3,int x4,int y1,int y2,int y3,int y4)
{
line(xcc+x1,ycc-y1,xcc+x2,ycc-y2);
line(xcc+x2,ycc-y2,xcc+x3,ycc-y3);
line(xcc+x3,ycc-y3,xcc+x4,ycc-y4);
line(xcc+x4,ycc-y4,xcc+x1,ycc-y1);
}
void translation()
{
cleardevice();
int tx,ty;
int x1,y1,x2,y2;
setbkcolor(0);
cout<<"\ntranslation() called ";
cout<<"\nenter the first vertex of rectangle :";
cin>>x1>>y1;
cout<<"\nenter the second vertex of rectangle :";
cin>>x2>>y2;
cout<<"\nenter the translation vectors tx and ty :";
cin>>tx>>ty;
cleardevice();
setcolor(getmaxcolor());
line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
line(getmaxx()/2,0,getmaxx()/2,getmaxy());
outtextxy(10,20,"red = original figure");
outtextxy(10,40,"blue = translated figure");
setcolor(4);
rectangle(xcc+x1,ycc-y1,xcc+x2,ycc-y2);
setcolor(1);
rectangle(xcc+x1+tx,ycc-(y1+ty),xcc+x2+tx,ycc-(y2+ty));
}

/*-------------------------------------------------------------------*/
void scaling()
{
float sx,sy;
int x1,y1,x2,y2;
cleardevice();
setbkcolor(0);
cout<<"\nscaling() called ";
cout<<"\nenter the first vertex of rectangle :";
cin>>x1>>y1;
cout<<"\nenter the second vertex of rectangle :";
cin>>x2>>y2;
cout<<"\nenter the scaling parameters sx and sy :";
cin>>sx>>sy;
cleardevice();
setcolor(getmaxcolor());
line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
line(getmaxx()/2,0,getmaxx()/2,getmaxy());
outtextxy(10,20,"red = original figure");
outtextxy(10,40,"blue = scaled figure");
setcolor(4);
rectangle(xcc+x1,ycc-y1,xcc+x2,ycc-y2);
setcolor(1);
rectangle(xcc+(x1*sx),ycc-(y1*sy),xcc+(x2*sx),ycc-(y2*sy));
}
/*-------------------------------------------------------------------*/
void reflection()
{
int x1,y1,x2,y2;
char c;
cleardevice();
setbkcolor(0);
cout<<"\nreflection() called :";
cout<<"\nenter the first vertex of rectangle :";
cin>>x1>>y1;
cout<<"\nenter the second vertex of rectangle :";
cin>>x2>>y2;
cout<<"\nenter the axis of reflection x/y:";
cin>>c;
cleardevice();
setcolor(getmaxcolor());
line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
line(getmaxx()/2,0,getmaxx()/2,getmaxy());
outtextxy(10,20,"red = original figure");
outtextxy(10,40,"blue = image ");
setcolor(4);
rectangle(xcc+x1,ycc-y1,xcc+x2,ycc-y2);
setcolor(1);
if(c=='x')
{
rectangle(xcc+x1,ycc+y1,xcc+x2,ycc+y2);
}
if(c=='y')
{
rectangle(xcc-x1,ycc-y1,xcc-x2,ycc-y2);
}
}

/*-------------------------------------------------------------------*/
void rotation()
{
cleardevice();
setbkcolor(0);
cout<<"\nrotation() called :";
float xx1,yy1;
float x1,y1,r;
double d;
cout<<"\nenter the center of circle :";
cin>>x1>>y1;
cout<<"\nenter the radius of circle :";
cin>>r;
cout<<"\nenter angle of rotation in radians :";
cin>>d;
cleardevice();
xx1=(x1*cos(d))-(y1*sin(d));
yy1=(x1*sin(d))+(y1*cos(d));

setcolor(getmaxcolor());
outtextxy(10,20,"red = original figure");
outtextxy(10,40,"blue = rotated figure");
line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
line(getmaxx()/2,0,getmaxx()/2,getmaxy());
setcolor(4);
circle(xcc+x1,ycc-y1,r);
line(xcc,ycc,xcc+x1,ycc-y1);
setcolor(1);
circle(xcc+xx1,ycc-yy1,r);
setcolor(15);
line(xcc,ycc,xcc+x1,ycc-y1);
line(xcc,ycc,xcc+xx1,ycc-yy1);
}
/*-----------------------------------------------------------------*/
void shearing()
{
cleardevice();
setbkcolor(0);
cout<<"\nShearing() called ";
int x1,y1,x2,y2,x3,y3,x4,y4;
int xx1,xx3,xx4,xx2,yy1,yy2,yy4,yy3;
int shx,shy;
char c;
cout<<"\nenter the value of x1,y1 (vertex of rectangle):";
cin>>x1>>y1;
cout<<"\nenter the value of x2,y2 :";
cin>>x2>>y2;
cout<<"\nenter the value of x3,y3 :";
cin>>x3>>y3;
cout<<"\nenter the value of x4,y4 :";
cin>>x4>>y4;
cout<<"\select the direction of shearing x/y :";
cin>>c;
if(c=='x')
{
cout<<"\nenter the shearing parameter shx :";
cin>>shx;
xx1=x1;
yy1=y1;
xx2=x2+shx;
yy2=y2;
xx4=x4;
yy4=y4;
xx3=x3+shx;
yy3=y3;
}
if(c=='y')
{
cout<<"\nenter the shearing parameter shy :";
cin>>shy;
xx1=x1;
yy1=y1;
xx2=x2;
yy2=y2;
xx4=x4;
yy4=y4+shy;
xx3=x3;
yy3=y3+shy;
}
cleardevice();
setcolor(getmaxcolor());
outtextxy(10,20,"red = original figure");
outtextxy(10,40,"blue = sheared figure");
line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
line(getmaxx()/2,0,getmaxx()/2,getmaxy());
setcolor(4);
figure(x1,x2,x3,x4,y1,y2,y3,y4);
setcolor(1);
figure(xx1,xx2,xx3,xx4,yy1,yy2,yy3,yy4);
}
/*------------------------------------------------------------------*/
void menu()
{
clrscr();
int x;
char c,a;
setbkcolor(4);
cout<<"\n=======MENU=======";
cout<<"\n1 : Translation   ";
cout<<"\n2 : Scaling       ";
cout<<"\n3 : Reflection    ";
cout<<"\n4 : Rotation      ";
cout<<"\n5 : Shearing      ";
cout<<"\n6 : Exit          ";
cout<<"\n\nEnter a choice from the menu :";
cin>>x;
switch(x)
{
case 1:translation();
break;
case 2:scaling();
break;
case 3:reflection();
break;
case 4:rotation();
break;
case 5:shearing();
break;
case 6:return;
}
cin>>a;
cleardevice();
cout<<"\nstill want to continue y/n:";
cin>>c;
if(c=='y')
{
cleardevice();
menu();
}
else
return;
}
void main()
{
int driver,mode;
driver=DETECT;
initgraph(&driver,&mode,"");
xcc=getmaxx()/2;
ycc=getmaxy()/2;
menu();
getch();
closegraph();
}


