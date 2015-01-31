/*matrix multiplication : HARSHIT */
#include"stdio.h"
#include"conio.h"
void main()
{
clrscr();
int a[5][5],b[5][5],c[5][5],i,j,k,s,r1,c1,r2,c2;
puts("\nenter the number of rows and coloumns of matrix 1 : ");
scanf("%d%d",&r1,&c1);
puts("\nenter the number of rows and coloumns of matrix 2 : ");
scanf("%d%d",&r2,&c2);
printf("\nthe order of first matrix is : %d * %d",r1,c1);
printf("\nthe order of second matrix is : %d * %d",r2,c2);
if(r1==c2)
{
puts("\nenter the elements of matrix 1 : ");
for(i=0;i<r1;i++)
for(j=0;j<c1;j++)
scanf("%d",&a[i][j]);
puts("\nthe matrix 1 you entered is : \n\t");
for(i=0;i<r1;i++)
{
for(j=0;j<c1;j++)
printf("%d\t",a[i][j]);
printf("\n");
}
puts("\nenter the elements of matrix 2 : ");
for(i=0;i<r2;i++)
for(j=0;j<c2;j++)
scanf("%d",&b[i][j]);
puts("\nthe matrix 2 you entered is : \n\t");
for(i=0;i<r2;i++)
{
for(j=0;j<c2;j++)
printf("%d\t",b[i][j]);
printf("\n");
}
for(i=0;i<r1;i++)
for(j=0;j<r1;j++)
{
s=0;
for(k=0;k<r1;k++)
s=s+(a[i][k]*b[k][j]);
c[i][j]=s;
}
puts("\nthe multiplication of matrix 1 & 2 : \n");
for(i=0;i<r1;i++)
{
for(j=0;j<r1;j++)
printf("%d\t",c[i][j]);
printf("\n");
}}
else
puts("\nmultiplication cannot be done ! ");
getch();
}
