//entering two-d array:HARSHIT

#include<stdio.h>
#include<conio.h>
void main()
{

 int a[3][3],i,j;
 clrscr();
  printf("Enter the array elements");
  for( i= 0;i<=2;i++)
   {
     for(j=0;j<=2;j++)
      {
       scanf("%d",&a[i][j]) ;
      }
   }
  printf("The elements of the array are");
  for( i =0;i<=2;i++)
   {
     for(j=0;j<=2;j++)
      {
	printf("%d",a[i][j]);
      }
     printf("\n");
     }
getch();
}