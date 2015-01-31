//checking matrix is symmetric or not:HASRHIT

#include<stdio.h>
# include<conio.h>
void main()
{
int a[10][10],n,i,j,flag;
clrscr();
printf("Enter order of the matrix : ");
scanf("%d",&n);
printf( "Enter the elements : \n");
	for(i=0;i<=n-1;i++)
	{
	  for(j=0;j<=n-1;j++)
	  {
	    scanf("%d",a[i][j]);
	    }
	}
	 flag = 1;
for(i=0;i<=n-1;i++)
    {
      for(j=i+1;j<=n-1;j++)
      {
	if((a[i][j] - a[i][j]) != 0)
	flag =0;
	break;
      }
   }
if(flag)
printf("Symmetric matrix ");
else
printf("Not a symmetric matrix");
getch();
}