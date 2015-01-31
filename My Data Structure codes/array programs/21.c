//finds the smallest number in the array:HARSHIT

#include<stdio.h>
# include<conio.h>
void main()
{
int small,a[100],i,n,s,pos;
clrscr( );
printf("How many elements in an array : ");
scanf("%d",&n);
printf("Enter the elements :\n ");
	for(i=0;i<=n-1;i++)
	{
	 scanf("%d",&a[i]);
	}
small=a[0];
pos = 0;
	for(i=1;i<=n-1;i++)
	{
	 if(small>a[i])
	 {
	   small=a[0];
	   pos =i;
	 }
	}
printf("the smallest of the entred nois%d\n",small);
printf("the position of the smallest no is %d",pos+1);
getch();
}