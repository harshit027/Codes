//transpose of a matrix:HARSHIT

#include<stdio.h>
# include<conio.h>
void main()
{
int a[10][10],b[10][10],i,j,m,n;
clrscr();
printf("Enter the order of the matrix\n");
printf("No. of rows : \n");
scanf("%d",&n);
printf("No. of columns :\n ");
scanf("%d",&m);
printf("Enter the matrix elements\n");
	for(i=0;i<=n-1;i++)
	  {
	   for(j=0;j<=m-1;j++)
	   {
	    scanf("%d\n",&a[i][j]);
	    b[j][i] = a[i][j];
	   }
	 }
printf("Matrix A was\n ");
	for(i=0;i<=n-1;i++)
	{
	  for(j=0;j<=m-1;j++)
	  {
	    printf("%d\n",a[i][j]);
	  }
	}
printf("Transpose of matrix A is \n");
	for(i=0;i<=m-1;i++)
	 {
	   for(j=0;j<=n-1;j++)
	   {
	  printf("%d\n",b[i][j]);
	   }
	}
getch( );
}