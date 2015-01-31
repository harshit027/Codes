import java.util.Scanner;

class RangeException extends Exception
{
	private int max,min,cur;
	RangeException(int mn,int mx,int cr)
	{
		this.min=mn;
		this.max=mx;
		this.cur=cr;
	}
	public String toString()
	{
		if(cur>max||cur<min)
		{
			return "Out of Range";
		}
		else
		return"Perfect";
	}
}

class MyExceptionType1
{
	public static void main(String args[])
	{

	     int age;
         try
	     {
		     Scanner obj=new  Scanner(System.in);
		     System.out.print("Enter the age of student :");
	         age=obj.nextInt();
	         RangeException r1=new RangeException(1,100,age);
	         throw r1;
	     }
	     catch(RangeException re)
	     {
	     	System.out.println(re.toString());
	     }
     }
 }