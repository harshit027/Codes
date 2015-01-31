/*floodfill algorithm :HARSHIT */

#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

void floodfill(int x,int y,int fillcolor,int oldcolor)
     {
		delay(4);

		if(getpixel(x,y)==oldcolor)
	       {
		putpixel(x,y,fillcolor);
		floodfill(x-1,y,fillcolor,oldcolor);
		floodfill(x+1,y,fillcolor,oldcolor);
		floodfill(x,y-1,fillcolor,oldcolor);
		floodfill(x,y+1,fillcolor,oldcolor);

		}

     }
void main()
{
clrscr();
int    driver=DETECT,mode,fcolor;
       int x1,x2,y1,y2;
       initgraph(&driver,&mode,"");

       cout<<"\nenter the first vertex of solid bar :";
       cin>>x1>>y1;
       cout<<"\nenter the second vertex of solid bar :";
       cin>>x2>>y2;
       cleardevice();
       bar(x1,y1,x2,y2);

       cout<<"\nenter the color to be replaced (1-14):";
       cin>>fcolor;
       cleardevice();
       bar(x1,y1,x2,y2);
       floodfill(x1,y2,fcolor,15);
       getch();
       closegraph();
	  }
