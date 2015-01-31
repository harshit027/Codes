#include<stdio.h>
#include<conio.h>

long  NibbleSort( unsigned long n)
{
	
	int *arr;
	arr= (int*) malloc(sizeof(int)*8);
	
	int x;
	int i,j,temp;
	unsigned long output;
	output=0;
	
	for(i=0;i<8;i++)
	{
		//printf("%d ,",(n >> (8*i)) & ((1<<8)-1));
		arr[i]=(n >> (4*i)) & ((1<<4)-1);
	}
	
	for(i=0;i<8;i++)
	printf("%d, ",arr[i]);
	
	//Sorting the byte elements
	for(i=0;i<8;i++)
    { 
       for(j=0;j<8-i;j++)
       {
         if(arr[j]>arr[j+1])
	     {  
	       temp=arr[j];
	       arr[j]=arr[j+1];
	       arr[j+1]=temp;
	     }
       } 
    }
    printf("\n");
    for(i=0;i<8;i++)
	printf("%d, ",arr[i]);
	
	for(i=7;i>=0;i--)
	{
		output=(output<<4) | arr[i];
		//printf("\n %d",output);
	}
	
	free(arr); 
	
	return output;
	
}

int main()
{
	unsigned long output;
	output=NibbleSort(12);
	printf("\nThe sorted long is %lu",output);
}
