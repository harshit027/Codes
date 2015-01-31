//radix sort:HARSHIT

#include<stdio.h>
#include<conio.h>
#define max 100
int a[max],n,i;
void main()
{
void input(void);
clrscr();
input();
getch();
}

void input(void)
{
void output(int a[],int n);
void radix_sort(int a[],int n);
printf("How many elements in the array : ");
scanf("%d",&n);
printf("\n");
printf("Enter the elements : \n");
for(i=0;i<=n-1;i++)
{
scanf("%d",&a[i]);
}
radix_sort(a,n);
printf("Sorted Array : \n");
output(a,n);
}

void radix_sort(int a[], int n)
{
int bucket[10][5],buck[10],b[10];
int i,j,k,l,num,div,large,passes;
div=1;
num=0;
large=a[0];
for(i=1;i<n;i++)
{
if(a[i]>large)
large=a[i];
}
while(large>0)
{
num++;
large=large/10;
}
for(passes=0;passes<num;passes++)
{
for(k=0;k<10;k++)
buck[k]=0;
for(i=0;i<n;i++)
{
l=(a[i]/div)%10;
bucket[l][buck[l]++]=a[i];
}
i=0;
for(k=0;k<10;k++)
{
for(j=0;j<buck[k];j++)
a[i++]=bucket[k][j];
}
div*=10;
}
}

void output(int a[],int n)
{
for(i=0;i<=n-1;i++)
{
printf("%d\n",a[i]);
}
}
