//trace and norm of the matrix:HARSHIT

#include<stdio.h>
#include<conio.h>
void main()
{
int a[10][10],i,j,n,m,trace=0,norm=0;
clrscr();
printf("Enter the order of the matrix(no. of rows and columns) : ");
scanf("%d%d",&n,&m);
if(n == m)
{
  printf("Trace is exist\n");
  printf("Enter matrix elements\n");
    for(i=0;i<=n-1;i++)
      {
      for(j=0;j<=m-1;j++)
	{
	  scanf("%d\n",&a[i][j]);
	}
      }

for(i=0;i<=n-1;i++)
  {
   trace+=a[i][i];
   for(j=0;j<=m-1;j++)
   {
     norm+=a[i][j]*a[i][j];
   }
  }
printf("Trace of the matrix :%d\n ",trace);
printf("Norm of the matrix :%d ",sqrt(norm));
}
else
printf("Trace and norm do not exist");
getch();
}