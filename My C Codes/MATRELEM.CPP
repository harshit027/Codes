/*calculating sum of diag,uptriangle,lotriangle, elements of a matrix*/
/*HARSHIT*/
#include<stdio.h>
#include<conio.h>
void main()
{
clrscr();
int a[3][3],i,j,s1=0,s2=0,s3=0;
printf("\nenter the elements of 'a' matrix : ");
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
scanf("%d",&a[i][j]);
}
printf("\nthe entered array 'a' is : \n");
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
printf("%d\t",a[i][j]);
printf("\n");
}
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
if(i==j)
s1=s1+a[i][j];
else
{
if(i<j)
s2=s2+a[i][j];
else
s3=s3+a[i][j];
}
}}
printf("\nsum of diagonal elements : %d",s1);
printf("\nsum of uptriange elements :%d",s2);
printf("\nsum of lotriangle elements :%d",s3);
getch();
}





