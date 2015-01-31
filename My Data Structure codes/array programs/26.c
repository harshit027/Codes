//checking if upper triangle or not:HARSHIT

#include<stdio.h>
#include<conio.h>
void main()
{
int a[10][10],i,j,n,flag;

clrscr();
printf("Enter the order of the matrix : ");
scanf("%d",&n);
printf("Enter matrix elements :\n ");
	for(i=0;i<=n-1;i++)
	 {
	   for(j=0;j<=n-1;j++)
	   {
	    printf("i=%dj=%d\n",i,j);
	    scanf("%d",&a[i][j]);
	   }
	 }
flag = 1;
	for(i=0;i<=n-2;i++)
	  {
	   for(j=i+1;j<=n;j++)
	    {
	      if(a[i][j] !=0)  flag = 0;
	      break;
	    }
	  }
if(flag)
	printf("Upper triangle matrix ");
else
	printf("Not a Upper triangle matrix");
getch();
}