//searching an element in array:HARSHIT

#include<stdio.h>
#include<conio.h>
void main()
{
int a[100],n,i,item,loc=-1;
clrscr();
printf("\nEnter the number of element:");
scanf("%d",&n);
printf("Enter the number:\n");
for(i=0;i<=n-1;i++)
   {
     scanf("%d",&a[i]);
   }
printf("Enter the no. to be search\n");
scanf("%d",&item);
for(i=0;i<=n-1;i++)
   {
    if(item==a[i])
      {
       loc=i;
       break;
     }
   }
if(loc>=0)

   printf("\n%dis found in position%d",item,loc+1);
   else
   printf("\nItem does not exits");
   getch();
     }

