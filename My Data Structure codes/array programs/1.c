//entering elements in array: HARSHIT

#include<stdio.h>
#include<conio.h>
void main()
{
int a[10],i;
clrscr();
  printf("Enter the array");
  for(i = 0;i <=9;i ++)
      {
       scanf("%d",&a[i]);
       }
 printf("The entered array is");
 for(i = 0;i <=9; i++)
     {
    printf("%d\n",a[i]);
      }
getch();
}