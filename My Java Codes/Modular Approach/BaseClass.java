public class BaseClass
{
	ChildClass c1;
	BaseClass()
	{
		c1=new ChildClass();
		System.out.println("I am the constructor of BaseClass");
		c1.Function1();
	}
	public static void main(String args[])
	{
		new BaseClass();
	}
}

