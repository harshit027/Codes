class Student
{
	protected
	int roll_no;
	String name;

	public
	Student()
	{
		roll_no=101;
		name="HARSHIT";
	}
	Student(int r,String n)
	{
		roll_no=r;
		name=n;
	}

}

class Graduate extends Student
{

	String degree;

	Graduate()
	{
		degree="B.E";
	}
	Graduate(String d)
	{
		//super(104,"SMITH"); //use of "super" as a constructor initialized
	   	degree=d;
	}
	Graduate(int r,String n,String d)
	{
		//super(r,n); //use of "super" as a constructor not initialized
		this("B Pharma"); //use of "this" as constructor
		//degree=d;
	}

	void showData()
	{
		System.out.println("STUDENT NAME---->"+name);
		System.out.println("ROLL NO--------->"+roll_no);
		System.out.println("DEGREE---------->"+degree);
		System.out.println("-----------------------------");
	}



}

class Inheritance
{
	public static void main(String args[])
	{
		Graduate g1=new Graduate();
		g1.showData();
		Graduate g2=new Graduate("B Com");
		g2.showData();
		Graduate g3=new Graduate(102,"JACK","B Sc");
		g3.showData();
	}
}