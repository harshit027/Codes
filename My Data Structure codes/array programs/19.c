//matrix multiplication:HARSHIT

#include<stdio.h>
#include<conio.h>
void main( )
     {
	int a[2][2], b[2][2],s[2][2];
	int i,j,k;
     clrscr();
	 printf("Enter first matrix:\n" );
    for( i=1;i<=2;i++)
    {
	for( j=1;j<=2;j++)
	{
	 printf("Enter%d%d\n",i,j);
	 scanf("%d",&a[i][j]);
	}
    }
printf("Enter second matrix:\n");
    for(i=1;i<=2;i++)
    {
	 for(j=1;j<=2;j++)
	 {
	  printf("Enter %d%d\n",i,j);
	  scanf("%d",&b[i][j]);
	}
    }

       for(i=1;i<=2;i++)
	{
	  for(j=1;j<=2;j++)
	    {
	    s[i][j]=0;
	      for(k=1;k<=2;k++)
		{
		  s[i][j] =s[i][j]+a[i][k]*b[k][j];
		}
	    }
	}

printf("Matrix Multiplication Is: \n");
for(i=1;i<=2;i++)
   {
     for (j=1;j<=2;j++)
       {
	printf("%d\n",s[i][j]);
       }
    }
getch();
}
