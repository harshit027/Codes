//matrix addition :HARSHIT

#include<stdio.h>
#include<conio.h>
void main ( )
{
	int a[2][2],b[2][2],s[2][2],i,j;
	clrscr ();
	printf("enter first matrix: \n");
		for ( i=1; i<=2; i++)
		{
		   for ( j=1; j<=2; j++)
		     {
			printf("Enter %d%d", i,j, "element:");
			scanf("%d",&a[i][j]);
		     }
	      }
	printf("enter second matrix: \n");
		for(i=1;i<=2;i++)
		{
		  for(j=1; j<=2;j++)
		  {
		    printf( "enter  %d%d",i + 1 ,j + 1 , "element:");
		    scanf("%d",&b[i][j])  ;
		  }
		}
	for (i=1;i<=2;i++)
	{
	  for (j=1;j<=2;j++)
	     {
	       s[i][j]= a[i][j]+b[i][j];
	      }
	}
printf("The addition matrix is:\n");
     for (i=1;i<=2;i++)
     {
       for (j=1;j<=2;j++)
	 {
	  printf("%d\n",s[i][j] );
	 }
     }
		     getch ();
		       }