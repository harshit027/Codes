//merging two arrays : HARSHIT

#include<stdio.h>
#include<conio.h>
void main()
{
int p,q,m,n,c;
int array1[100],array2[100],array3[200];
puts("Enter number of element of the first sorted array");
scanf("%d",&p);
puts("Enter element of the first sorted array");
for(m=0;m<=p;m++)
scanf("%d",&array1[m]);
puts("Enter number of element of the second sorted array");
scanf("%d",&q);
puts("Enter element of the second array");
for(n=0;n<=q;n++)
scanf("%d",&array2[n]);
c=0;
m=0;
n=0;
while((m<q)&&(n<q))
{
if(array1[m]<=array2[n])
array3[c]=array1[m++];
else
array3[c]=array2[n++];
c++;
}
while(m<p)
{
array3[c]=array1[m];
c++;
m++;
}
while(n<q)
{
array3[c]=array2[n];
c++;
n++;
}
puts("merged array in ascending order");
for(m=0;m<=c;m++)
printf("%d",array3[m]);
}
