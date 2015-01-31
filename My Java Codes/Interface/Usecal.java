import java.util.Scanner;
/*interface cal //available in f:\myjava\mypack
{

	void add();
	void subtract();
	void getData();
	void show();

}*/

class Calculator implements cal
{
	double a,b,c;
	public void getData()
	{
		Scanner obj=new Scanner(System.in);
	    System.out.println("Enter the numbers :");
	    a=obj.nextDouble();
	    b=obj.nextDouble();
	}
	public void add()
	{
		System.out.println("Addition performed !");
       c=a+b;
	}

	public void subtract()
	{
		System.out.println("Subtraction performed !");
	   c=a-b;
	}

	public void show()
	{
		System.out.println("Result="+c);
	}

}

class Usecal
{
	public static void main(String args[])
	{
		cal ref;
		Calculator c=new Calculator();
		ref=c;
		c.getData();
		c.add();
		c.show();

	}
}