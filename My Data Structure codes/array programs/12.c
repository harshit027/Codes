//initialization of two-d array:HARSHIT

#include<stdio.h>
#include<conio.h>
main()
{

static int a[3][2] = {
			{100,200},
			{300,400},
			{500,600}
		  };
int *ptr1,i,j,n,m;
clrscr();
ptr1=&a[0][0];
n=3;
m=2;
for(i=0;i<=n-1;i++)
{
printf("\n");
for(j=0;j<=m-1;j++)
{
printf("%d\t",*ptr1);
ptr1++;
}}
getch();
}
