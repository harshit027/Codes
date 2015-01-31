//dyanamic length array:HARSHIT

#include<stdio.h>
#include<conio.h>
 void main( )
	{
	  int a[100],i,n;
clrscr( );
	printf("HOW MANY NO. TO STORE IN THE ARRAY ");
	scanf("%d",&n);
	printf("\nENTER THE NUMBERS:\n");
	for(i=0;i<=n-1;i++)
	  {
	   scanf("%d",&a[i]);
	  }
	printf("CONTENTS OF THE ARRAY ARE :\n");
	for(i=0;i<=n-1;i++)
	{
	      printf("%d\n",a[i]);
	}
getch();
}