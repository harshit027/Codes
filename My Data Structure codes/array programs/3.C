//entering element at desired place:HARSHIT

#include<stdio.h>
#include<conio.h>
int i,len,pos,num;
void main()
{
int a[100];
void insert(int a[], int, int, int);
clrscr();
printf("Enter integers to be read");
scanf("%d",&len);
printf("Enter integers");
    for(i=0;i<=len;i++)
      {
	scanf("%d",&a[i]);
      }
printf("Enter integer to be inserted");
scanf("%d",&num);
printf("Enter position in the array for insertion");
scanf("%d",&pos);
--pos;
insert(a,len,pos,num);
}
void insert (int a[], int len, int pos, int num)
{
    for(i=len;i>=pos;i--)
      {
	a[i+1]=a[i];
      }
	a[pos]=num;
	  if(pos>len)
	    {
		printf("insertion outside the array");
	    }
	len++;
	printf("New array");
for(i=0;i<len;i++)
{
printf("%d\n",a[i]);
}
getch();
}