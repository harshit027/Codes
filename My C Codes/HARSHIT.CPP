
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>

void boundryfill(int x,int y,int fillcolor,int bcolor)
     {
		delay(2);

		int present=getpixel(x,y);
		if(present!=3 && present!=fillcolor)
	       {
			putpixel(x,y,fillcolor);
			boundryfill(x+1,y,fillcolor,bcolor);
			boundryfill(x-1,y,fillcolor,bcolor);
			boundryfill(x,y+1,fillcolor,bcolor);
			boundryfill(x,y-1,fillcolor,bcolor);
	       }

     }
void main()
     {
	 cleardevice();
	 clrscr();
	 int gd=DETECT,gm,fillcolor,bcolor;
	 initgraph(&gd,&gm,"");
	 setcolor(3);
	 rectangle(100,100,150,150);
	 cout<<"enter the new value of color\n";
	 cin>>fillcolor;
	 boundryfill(101,101,fillcolor,3);
	 getch();
     }
