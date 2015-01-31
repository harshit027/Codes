#include<.h>
#include<stdlib.h>
void init()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"");
}

void floodfill(int x,int y,int fillcolor,int oldcolor)
     {
		delay(3);

		if(getpixel(x,y)==oldcolor)
	       {
		putpixel(x,y,fillcolor);
		floodfill(x+1,y,fillcolor,oldcolor);
		floodfill(x-1,y,fillcolor,oldcolor);
		floodfill(x,y+1,fillcolor,oldcolor);
		floodfill(x,y-1,fillcolor,oldcolor);
		}

     }
void main()
{
clrscr();
int gd=DETECT,gm,fillcolor,oldcolor,i,j;
       initgraph(&gd,&gm,"");
       bar(220,140,320,240);
       cout<<"enter the new value of color\n";
       cin>>fillcolor;
       floodfill(220,140,fillcolor,15);

       getch();
	  }
