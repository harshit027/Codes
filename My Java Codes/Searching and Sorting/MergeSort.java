package algos;

public class MergeSort {

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
			int mid=left+(right-left)/2;
			sort(a,left,mid);
			sort(a,mid+1,right);
			merge(a,left,mid,right);
		}
		
	}
	
	public static void merge(int[] a, int left,int mid,  int right)
	{
		
		int n1=mid-left+1;
		int n2=right-mid;
		int k=left;
		int [] L= new int[n1];
		int[] R= new int[n2];
		int i=0,j=0;
		for(int m=0;m<n1;m++)
			L[m]=a[left+m];
		for(int m=0;m<n2;m++)
			R[m]=a[mid+1+m];
		
		while(i<n1 && j<n2)
		{
			if(L[i]<=R[j])
				a[k++]=L[i++];
			else
				a[k++]=R[j++];
				
		}
		while(i<n1)
			a[k++]=L[i++];
		while(j<n2)
			a[k++]=R[j++];
	}
}
