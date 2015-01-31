/*inputing and displaying a matrix :HARSHIT*/
#include"stdio.h"
#include"conio.h"
void main()
{
clrscr();
int a[10][10],i,j,n;
puts("\nenter the order of matrix : ");
scanf("%d",&n);
printf("\nenter the elements of matrix : ");
for(i=0;i<n;i++)
for(j=0;j<n;j++)
scanf("%d",&a[i][j]);
printf("\n u have entered \n\n");
for(i=0;i<n;i++)
{
printf("|");
for(j=0;j<n;j++)
printf(" %d ",a[i][j]);
printf("|\n\n");
}
getch();
}