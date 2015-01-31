import java.util.Scanner;

class ExceptionType2
{
	public static void main(String args[])
	{
		String arr[]={"cs","it","me","ce","ec"};
		Scanner obj=new Scanner(System.in);
		try
		{
			int i=0;
			System.out.print("\nEnter the rollnumber (BE) :");
			String enr=obj.nextLine();
			if(enr.length()!=12)
			{
				ArithmeticException e1=new ArithmeticException("Invalid enrollment number !");
				throw e1;
			}
			/*for(i=0;i<arr.length;i++)
			{
				if(enr.regionMatches(true,0,arr[i],4,2)==true)
				{
					break;
				}
			}
			if(i!=arr.length)
			{
				ArithmeticException e2=new ArithmeticException("\nInvalid Branch !");
				throw e2;
			}*/
			else
			{
				System.out.println("Perfect  !");
			}
		}
		catch(ArithmeticException ae)
		{
			System.out.println(ae.getMessage());

		}
	}
}