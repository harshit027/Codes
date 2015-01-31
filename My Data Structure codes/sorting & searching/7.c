//searching element in array:HARSHIT

#include<stdio.h>
#include<conio.h>
void main()
{
int a[100],i,loc,mid,beg,end,n,flag=0,item;
clrscr();
printf("How many elements");
scanf("%d",&n);
printf("Enter the element of the array\n");
for(i=0;i<=n-1;i++)
{
scanf("%d",&a[i]);
}
printf("Enter the element to be searching\n");
scanf("%d",&item);
loc=0;
beg=0;
end=n-1;
while((beg<=end)&&(item!=a[mid]))
{
     mid=((beg+end)/2);
       if(item==a[mid])
	 {
	   printf("search is successfull\n");
	   loc=mid;
	   printf("position of the item%d\n",loc+1);
	   flag=flag+1;
	 }
      if(item<a[mid])
	end=mid-1;
 else
	beg=mid+1;
}
if(flag==0)
{
printf("search is not successfull\n");
}
getch();
}


