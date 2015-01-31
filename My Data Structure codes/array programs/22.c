//maximum and minimum element in the array:HARSHIT

#include<stdio.h>
# include<conio.h>
void main()
{
int a[100],i,n,max,min;
clrscr();
printf("How many elements in the array : ");
scanf("%d",&n);
printf("Enter the elements : \n");
  for(i=0;i<=n-1;i++)
    {
     scanf("%d",&a[i]);
    }
max = a[0];
min = a[0];
  for(i=1;i<=n-1;i++)
   {
    if(max<a[i])
    max = a[i];
   if(min>a[i])
   min = a[i];
  }
printf("maximum element in the array is :%d\n ",max);
printf("minimum element in the array is : %d\n",min);
getch();
}