//sum of elements of array:HARSHIT

#include<stdio.h>
#include<conio.h>
int funarray(int [], int);
void main()
{
    int a[10],i,sum=0;
    clrscr();
  printf("Enter the array");
  for(i =0;i<=9;i++)
    {
     scanf("%d",&a[i]);
    }
  sum=funarray(a,9);
  printf("The sum of array elements is%d",sum);
  getch();
  }

int funarray(int p[], int n)
 {
    int i,s=0;
    for(i=0;i<=n;i++)
     {
       s=s+p[i];
       }
    return(s);
    }