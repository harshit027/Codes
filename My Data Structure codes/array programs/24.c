//entering the matrix of order of our choice:HARSHIT

#include<stdio.h>
# include<conio.h>
void main()
{
int a[' '][' '];
int n,i,j,m;
clrscr();
printf("enter order of matrix");
scanf("%d\n",&n);
printf("enter matrix elements\n");
	for(i=1;i<=n;i++)
	 {
	  for(j=1;j<=n;j++)
	  {
	   printf("a%d%d=",i,j);
	   scanf("%d\n",&a[i][j]);
	  }
	}
printf("display\n");
for(i=1;i<=n;i++)
  {
  for(j=1;j<=n;j++)
   {
    printf("a%d%d=",i,j);
    printf("%d\n",a[i][j]);
   }
  }
getch();
}