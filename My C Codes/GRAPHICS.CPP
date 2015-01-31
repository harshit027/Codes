#include"dos.h"
#include"conio.h"
#include"graphics.h"

void main()
{

clrscr();
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\turboc3\\bin ");
rectangle(100,50,300,150);
line(100,50,300,150);
line(100,150,300,50);

getch();
closegraph();

}