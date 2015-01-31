#include"iostream.h"
#include"conio.h"
#include"graphics.h"
#include"dos.h"
void gra1()				//Function definition #1
{
clrscr();
char msg[33];
int gdriver=DETECT,gmode,errorcode,c1x,c2x,c3x,c4x,c5x,c6x;
int c1y,c2y,c3y,c4y,c5y,c6y;
c1x=c2x=270;                    //       c1   c3
c3x=c4x=370;                    //   c5           c6
c5x=220;c6x=420;                //       c2   c4
c1y=c3y=20;
c2y=c4y=120;
c5y=c6y=70;
initgraph (&gdriver, &gmode," c:\\tc\bgi");
setfillstyle(8,8);
setcolor(7);
line(0,300,640,300);
floodfill(320,240,7);
setcolor(4);
line(c1x,c1y,c2x,c2y);
line(c1x,c1y,c3x,c3y);
line(c1x,c1y,c4x,c4y);
line(c2x,c2y,c3x,c3y);
line(c2x,c2y,c4x,c4y);
line(c3x,c3y,c4x,c4y);
line(c1x,c1y,c5x,c5y);
line(c5x,c5y,c2x,c2y);
line(c3x,c3y,c6x,c6y);
line(c4x,c4y,c6x,c6y);       		//DRAW THE LOGO OF PACK
setfillstyle(1,15);
floodfill(320,72,4);
floodfill(320,68,4);
floodfill(240,70,4);
floodfill(400,70,4);
setfillstyle(1,4);
floodfill(300,70,4);
floodfill(340,70,4);

settextstyle(10,0,4);
setcolor(15);
outtextxy(100,150,"CENTRAL LIBRARY");

setcolor(15);
line (320-150,320-13,320+150,320-13);
line (320-150,320+12,320+150,320+12);
line (320-150,320-13,320-150,320+12);
line (320+150,320+12,320+150,320-13);
int s=30,w;
gotoxy(20,23);
cout<<"LOADING . . .";
for (int x1=171,x2=171,y1=308,y2=331,y=1,S=0;x1<470;x1++,x2++,y++,S++)
{
setcolor(4);
line (x1,y1,x2,y2);
w=(x1-169)/3;
for (int i=34; i<=78; i++)
{
gotoxy(i,23) ;
cout <<" " ;
}
gotoxy(34,23); cout<<w<<"%";
if (x2>270) s=0;
if (x2>370) s=0;						       //for delay
if (x2==320)
delay(0);
else
delay(s);
}
delay(0);
for (int i=27; i<=78; i++)
{
gotoxy(i,23) ;
cout <<" " ;
}

gotoxy(28,23);
cout<<"COMPLETE";
gotoxy(20,25);
cout<<"PRESS ANY KEY TO CONTINUE ";
getch();
closegraph();

}
void gra2()                             //Function definition *2
{
clrscr();                               //To make a designer ellipse
int gd=DETECT,gm;
initgraph(&gd, &gm, "c:\\turboc2\\bin");

setfillstyle(10,9);                      //to fill the second screen
floodfill(410,250,15);
floodfill(225,215,15);
floodfill(275,210,15);
floodfill(350,215,15);
floodfill(390,210,15);
floodfill(423,205,15);
floodfill(423,230,15);
floodfill(270,244,15);
floodfill(300,200,15);

setcolor(4);
ellipse(320,240,0,360,300,150);
settextstyle(8,0,4);
settextjustify(1,1);
setcolor(4);
outtextxy(320,170,"PRESENTED BY");
delay(1000);
settextstyle(8,0,4);
setcolor(4);
outtextxy(320,220,"");
delay(1000);
settextstyle(7,0,5);
setcolor(15);
outtextxy(320,265,"HARSHIT TIWARI");
delay(1000);

for (int stangle=0;!kbhit();stangle++)
{
setcolor(4);
ellipse(320,240,stangle,
stangle+20,300,150);
ellipse(320,240,stangle+180,stangle+200,300,150);
delay(9);
setcolor(14);
ellipse(320,240,stangle-1,stangle+19,300,150);
ellipse(320,240,stangle-1+180,stangle+199,300,150);

}
getche();

}


void bfill2(int x,int y,int fillcolor,int bcolor)
{
delay(1);

int present=getpixel(x,y);
if(present!=bcolor && present!=fillcolor)
{
putpixel(x,y,fillcolor);

bfill2(x-1,y,4,15);
bfill2(x,y+1,4,15);
bfill2(x,y-1,4,15);
bfill2(x+1,y,4,15);
}
}
void bfill1(int x,int y,int fillcolor,int bcolor)
{
int n=fillcolor;
int present=getpixel(x,y);
if(present!=bcolor && present!=fillcolor)
{
putpixel(x,y,fillcolor);

bfill1(x-1,y,n,15);
bfill1(x,y+1,n,15);
bfill1(x,y-1,n,15);
bfill1(x+1,y,n,15);
}
}


void grap1()
{
int driver =DETECT,mode;
initgraph(&driver,&mode,"");
setbkcolor(8);
setcolor(1);
ellipse(300,120,0,360,200,70);

settextstyle(3,0,3);
setcolor(14);
outtextxy(130,105,"----CENTRAL LIBRARY----");

delay(3000);

settextstyle(2,0,5);
outtextxy(250,220,"LOADING....");
setcolor(15);
rectangle(250,250,350,260);
bfill2(251,259,4,15);
setcolor(14);
outtextxy(20,400,"Press enter to continue !");
getch();
closegraph();
}

void grap2()
{
int d=0,m;
initgraph(&d,&m,"");
setbkcolor(15);
delay(3000);
settextstyle(3,0,6);
setcolor(1);
outtextxy(150,100,"HARSHIT");
setcolor(15);
circle(50,100,20);
bfill1(50,100,1,15);
delay(3000);

setcolor(4);
outtextxy(250,200,"KUMAR");
setcolor(15);
circle(50,200,20);
bfill1(50,200,4,15);
delay(3000);

setcolor(2);
outtextxy(350,300,"TIWARI");
setcolor(15);
circle(50,300,20);
bfill1(50,300,2,15);


getch();
closegraph();
}

void main()
{
clrscr();
//gra1();
//gra2();
int d=0,m;
initgraph(&d,&m,"");
gra1();
gra2();
getch();
closegraph();
}
