/*boundary fill algorithm :HARSHIT */
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>


void floodfill(int x,int y,int fillcolor,int oldcolor)
     {
		delay(4);

		if(getpixel(x,y)==oldcolor)
	       {
		putpixel(x,y,fillcolor);
		floodfill(x+1,y,fillcolor,oldcolor);
		floodfill(x-1,y,fillcolor,oldcolor);
		floodfill(x,y+1,fillcolor,oldcolor);
		floodfill(x,y-1,fillcolor,oldcolor);
		}

     }
void boundryfill(int x,int y,int fillcolor,int bcolor)
     {
		delay(4);

		int present=getpixel(x,y);
		if(present!=bcolor && present!=fillcolor)
	       {
			putpixel(x,y,fillcolor);
			boundryfill(x+1,y,fillcolor,bcolor);
			boundryfill(x-1,y,fillcolor,bcolor);
			boundryfill(x,y+1,fillcolor,bcolor);
			boundryfill(x,y-1,fillcolor,bcolor);
	       }

     }
void changecolor(int x,int y,int fcolor)
     {
	 int ocolor;
	 char c;
	 cout<<"\nDo you want to change the color ? ";
	 cin>>c;
	 if(c=='y')
	 {
	 ocolor=fcolor;
	 cout<<"\nEnter the new choice of color :";
	 cin>>fcolor;
	 floodfill(x+1,y+1,fcolor,ocolor);
	 }
	 else
	 return;

     }

void main()
     {

	 clrscr();
	 int gd=DETECT,gm,fcolor,bcolor;
	 int x1,x2,y1,y2;
	 initgraph(&gd,&gm,"");
	 cout<<"\ndifference in min x/y and max x/y should not be more than 50 :\n";
	 cout<<"\nenter the 1st vertex of rectangle :";
	 cin>>x1>>y1;
	 cout<<"\nenter the 2nd vertex of rectangle :";
	 cin>>x2>>y2;
	 cout<<"\nenter the boundary color (1-15) : ";
	 cin>>bcolor;
	 cout<<"\nenter the fill color (1-15) : ";
	 cin>>fcolor;
	 cleardevice();
	 rectangle(x1,y1,x2,y2);
	 boundryfill(x1+1,y2-1,fcolor,bcolor);
	 changecolor(x1+1,y1+1,fcolor);
	 getch();
	 closegraph();
     }
