/*demonstration of sorting : HARSHIT */

#include"stdio.h"
#include"conio.h"
/*------------------------------------------------------------*/
/*code for bubble sort function*/
void bubblesort(int a[], int n)
{
puts("\n\nbubblesort() called : ");
int i,j,check=1,temp;
for(i=0;i<n-1 && check==1;i++)
{
check=0;
for(j=0;j<n-i-1;j++)
{
if(a[j]>a[j+1])
{
check=1;
temp=a[j+1];
a[j+1]=a[j];
a[j]=temp;
}}}
puts("\nthe sorted list is :");
for(i=0;i<n;i++)
printf("%d  ",a[i]);
}
/*---------------------------------------------------------------*/
/*code for selection sort */
void selectionsort(int a[],int n)
{
puts("\nselection sort() called :");
{
int i,j,large,index;
for(i=n-1;i>0;i--)
{
large=a[0];
index=0;
for(j=1;j<=i;j++)
{
if(a[j]>large)
{
large=a[j];
index=j;
}}
a[index]=a[i];
a[i]=large;
}
puts("\nthe sorted list is :");
for(i=0;i<n;i++)
printf("%d  ",a[i]);
}}
/*--------------------------------------------------------------*/
/*code for insertion sort*/
void insertionsort(int a[],int n)
{
puts("\ninsertion sort() called :");
int i,j,insert;
for(i=1;i<=n-1;i++)
{
insert=a[i];
for(j=i-1;j>=0&&insert<a[j];j--)
{
a[j+1]=a[j];
}
a[j+1]=insert;
}
puts("\nthe sorted list is :");
for(i=0;i<n;i++)
printf("%d  ",a[i]);
}
/*--------------------------------------------------------------*/
/*code for quick sort*/
void quicksort(int a[],int lb,int ub)
{
puts("\nquick sort() called:");
int l,r,pivot,temp;
l=lb;
r=ub;
if(lb<=ub)
pivot=a[lb];
while(l<=r)
{
while(a[l]<=pivot && l<r)
l++;
while(a[r]>pivot)
r--;
if(l<r)
temp=a[l];
a[l]=a[r];
a[r]=temp;
}
a[lb]=a[r];
a[r]=pivot;
if(lb<r-1)
quicksort(a,lb,r-1);
if(r+1<ub)
quicksort(a,r+1,ub);
}
void qsort(int a[],int l,int h)
{
puts("\nqsort() called :");
int temp,low,high,key;
low=l;
high=h;
key=a[(high+low)/2];
do
{
while(key>a[low])
low++;
while(key<a[high])
high--;
if(low<=high)
{
temp=a[low];
a[low++]=a[high];
a[high--]=temp;
}
}while(low<=high);
if(l<high)
qsort(a,l,high);
qsort(a,low,h);
}
/*---------------------------------------------------------*/
/*creation of a max heap */
void createheap(int a[], int n)
{
puts("\ncreateheap () called : ");
int i,s,f,x;
for(i=1;i<n;i++)
{
s=i;
x=a[i];
f=(s-1)/2;
while (s>0&&a[f]<x)
{
a[s]=a[f];
s=f;
f=(s-1)/2;
}
a[s]=x;
}
puts("\nthe created heap is :");
for(i=0;i<n;i++)
printf("%d  ",a[i]);
}

/*sorting the created heap */
void heapsort(int a[],int n)
{
puts("\n\nheapsort() called :");
int i,s,f,x;
createheap(a,n);
for(i=n-1;i>0;i--)
{
x=a[i];
a[i]=a[0];
f=0;
if(i==1)
s=-1;
else
s=1;
if(i>2&&a[2]>a[1])
s=2;
while(s>=0&&x<a[s])
{
a[f]=a[s];
f=s;
s=2*f+1;
if(a[s+1]>a[s]&& (s+1)<=(i-1))
s=s+1;
if(s>i-1)
s=-1;
}
a[f]=x;
}
puts("\nthe sorted list is :");
for(i=0;i<n;i++)
printf("%d  ",a[i]);
}
/*---------------------------------------------------------*/
/*displays the sorted list*/
void display(int a[],int n)
{
puts("\nthe sorted list is : ");
int i;
for(i=0;i<n;i++)
printf("%d  ",a[i]);
}
/*------------------------------------------------------*/
void main()
{
clrscr();
int a[20],i,n,l;
puts("\nenter the number of elements to be stored :");
scanf("%d",&n);
puts("\nenter the elements of array : ");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
puts("\nthe elments you entered or unsorted list is :");
for(i=0;i<n;i++)
printf("%d  ",a[i]);
bubblesort(a,n);
getch();
}
/*-----------------------------------------------------*/
