
public class ChangeReturn {

	public static void main(String args[])
	{
		int n=10;
		int [] S={1,2,3};
	    int [] table= new int[n+1];
	    table[0]=0;
	    for(int i=1; i<n+1;i++)
	    {
	    	int min=n;
	    	for(int j=0;j<S.length;j++)
	    	{
	    		if(i>=S[j])
	    		{
	    			if(table[i-S[j]]+1<min)
	    				min=table[i-S[j]]+1;
	    		}
	    	}
	    	table[i]=min;
	    }
	    for(int i=0;i<table.length;i++)
	    System.out.println(table[i]);
	}
	
}
