import java.util.Scanner;

class Student
{
	private String sname;
	private int age;

	public void getData()
	{
		Scanner obj=new Scanner(System.in);

		System.out.println("Enter the name :");
		sname=obj.nextLine();
		System.out.println("Enter the age :");
		age=obj.nextInt();
	}
	public void showData()
	{
		System.out.println("Name = "+sname);
		System.out.println("Age = "+age);
		System.out.println("--------------------------------");
	}
}

	class Foreach
	{
		public static void main(String args[])
		{
			Student s[]=new Student[5];
			int i;
			for(i=0;i<5;i++)
			s[i]=new Student();

			for(Student t:s)
			t.getData();
			for(Student t:s)
			t.showData();
		}
	}


