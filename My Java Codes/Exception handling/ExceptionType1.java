//the exception object is thrown implicitly by jre

import java.util.Scanner;
class ExceptionType1
{
	public static void main(String[]args)
	{
		int i;
		int a[]=new int[10];
		for(i=1;i<10;i++)
		a[i]=i;
		int s=0,n;
		try
		{
			Scanner obj=new Scanner(System.in);
			System.out.println("Enter the number of integers ");
			n=obj.nextInt();
			for(i=0;i<n;i++)
			{
				s+=a[i];
			}
			System.out.println("The sum = "+s);
		}
		catch(ArrayIndexOutOfBoundsException ae)
		{
			System.out.println(ae.toString());
		}
	}
}