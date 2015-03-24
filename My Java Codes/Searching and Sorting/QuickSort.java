package algos;

public class QuickSort {

	public static void main(String args[])
	{
		int[] a={4,3,5,7,10,14,15,17,1,2,8,9};
		sort(a,0,a.length-1);
		for(int i=0;i<a.length;i++)
			System.out.print(a[i]+",");
	}
	
	public static void sort(int[] a, int left, int right)
	{
		if(left<right)
		{
			int pivot=a[right];
			int i=left-1;
			for(int j=left;j<right;j++)
			{
				if(a[j]<pivot)
				{
					i++;
					int temp=a[j];
					a[j]=a[i];
					a[i]=temp;
				}
			}
			int temp=a[i+1];
			a[i+1]=a[right];
			a[right]=temp;
			
			int p=i+1;
			
			sort(a, left, p-1);
			sort(a,p+1,right);
		}
		
		
	}
}
