package algos;

public class BinarySearch {

	public static void main(String args[])
	{
		int[] a= {1,2,3,4,5,6,7,8};
		System.out.println(search(a,6,0,a.length));
	}
	
	public static int search(int []a, int n, int left, int right)
	{
		if(left<=right)
		{
			int mid=(left+right)/2;
			if(n==a[mid])
				return mid;
			if(n<a[mid])
				return search(a,n,left,mid-1);
			else
				return search(a,n,mid+1,right);
		}
		
		
		return -1;
	}
}
