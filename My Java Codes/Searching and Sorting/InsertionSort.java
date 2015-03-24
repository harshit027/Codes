package algos;

public class InsertionSort {
	
	public static void main(String args[])
	{
		int[] a={4,3,5,7,10,14,15,17,1,2,8,9};
		sort(a);
		for(int i=0;i<a.length;i++)
			System.out.print(a[i]+",");
	}
	
	public static void sort(int [] a)
	{
		for(int i=1;i<a.length;i++)
		{
			int key=a[i];
			int j=i-1;
			while(j>=0 && a[j] >key)
			{
				a[j+1]=a[j];
				j=j-1;
			}
			a[j+1]=key;
		}
	}
	
}
