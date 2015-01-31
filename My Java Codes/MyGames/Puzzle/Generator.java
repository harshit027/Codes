import java.util.Random;

class Generator
{
	public static void main(String args[])
	{
		Random rnd=new Random();
		int n[]=new int[]{0,1,2,3,4,5,6,7,8,9};
		int m[]=new int[10];
		int p=9,k=0;
	do
		{
		   int i=rnd.nextInt(p);
		   m[k]=n[i];
	       for(int j=i;j<p;j++)
		   {
              n[j]=n[j+1];

		   }
           p--;
           k++;
	   }while(p>0);
		for(int i=0;i<9;i++)
		System.out.print(m[i]);
	}
}

