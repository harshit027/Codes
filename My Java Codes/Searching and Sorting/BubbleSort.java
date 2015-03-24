package algos;

public class BubbleSort {

	public static void main(String args[])
	{
		int[] a={4,3,5,7,10,121,14,15,17,1,2,8,9};
		sort(a);
		for(int i=0;i<a.length;i++)
			System.out.print(a[i]+",");
	}
	
	public static void sort(int[] a)
	{
		for(int i=0;i<a.length;i++)
		{
			for(int j=i+1;j<a.length;j++)
			{
				if(a[i]>a[j])
				{
					int temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
			}
		}
		
	}
}
