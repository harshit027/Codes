#include<stdio.h>
#include<conio.h>
int revint(int);
void main()
{
int n,result;
clrscr();
printf("Eneter the no");
scanf("%d",&n);
result=revint(n);
printf("The reverse of number %d is %d",n,result);
getch();
}
int revint(int p)
{
int d;
static int r=0;
if(p==0)
{
return(p);
}
else
{
d=p%10;
r=r*10+d;
revint(p/10);
}
return(r);
}
