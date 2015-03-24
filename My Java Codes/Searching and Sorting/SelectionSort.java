package algos;

public class SelectionSort {

	public static void main(String args[])
	{
		int[] a={4,3,5,7,10,14,15,17,1,2,8,9};
		sort(a);
		for(int i=0;i<a.length;i++)
			System.out.print(a[i]+",");
	}
	
	public static void sort(int [] a)
	{
	
		for(int i=0;i<a.length;i++)
		{
			int min=a[i];
			int minindex=-1;
			for(int j=i+1;j<a.length;j++)
			{
				if(a[j]<min)
				{
					min=a[j];
					minindex=j;
				}
			}
			if(min<a[i])
			{
				int temp=a[i];
				a[i]=a[minindex];
				a[minindex]=temp;
			}
		}
	}
}
