package algos;

public class HeapSort 
{

	private int []a;
	private int size;
	private int left, right, smallest;
	
	HeapSort(int size)
	{
		this.size=size;
		a=new int[size];
	}
	public void buildHeap(int []a)
	{
		size= a.length-1;
		for(int i=size/2;i>=0;i--)
		{
			
			heapify(a,i);
		}
	}
	
	public void heapify(int []a, int i)
	{
		left=2*i+1;
    	right=2*i+2;
    	if(left <= size && a[left] < a[i]){
    		smallest=left;
    	}
    	else{
    		smallest=i;
    	}
    	
    	if(right <= size && a[right] < a[smallest]){
    		smallest=right;
    	}
    	if(smallest!=i){
    		swap(i,smallest);
    		heapify(a, smallest);
    	}
	}
	
	public void swap(int i, int j)
	{
    	int t=this.a[i];
    	this.a[i]=a[j];
    	this.a[j]=t; 
    }
	
	public void sort(int []a)
	{
		this.a=a;
		buildHeap(a);
		
		for(int i=size;i>0;i--){
    		swap(0, i);
    		size=size-1;
    		heapify(a, 0);
    	}
	}
	
	public static void main(String args[])
	{
		int []arr={3,5,1,2,4,10,11,12,13,15,18,21,29,22,24,100,24,23};
		int []k= new int[4];
		HeapSort heap=new HeapSort(k.length);
		for(int i=0;i<k.length;i++)
			k[i]=arr[i];
    	heap.sort(k);
    	for(int i=0;i<k.length;i++)
    	{
    		System.out.print(k[i] + " ");
    	}
    	
    	for(int i=k.length;i<arr.length;i++)
    	{
    		if(k[0]>arr[i])
    		{
    			k[0]=arr[i];
    			heap.sort(k);
    		}
    	}
    	for(int i=0;i<k.length;i++)
    	{
    		System.out.print(k[i] + " ");
    	}
    	
    	
	}
}
