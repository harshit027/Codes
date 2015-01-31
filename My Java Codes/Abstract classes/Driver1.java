import java.util.Scanner;

abstract class Student
{
	int rollno;
	String name;
	double percent=0;

	abstract void getData();
	abstract void  calPercent();
	void display()
	{
		System.out.println("\nName : "+name);
		System.out.println("\nPercent :"+percent);
	}
}

class SchoolStudent extends Student
{
	int phy,che,mat,hin,eng;
	Scanner obj=new Scanner(System.in);
	void getData()
	{

		System.out.print("\nEnter the rollno : ");
		rollno=obj.nextInt();
		System.out.print("\nEnter the name :");
		obj.nextLine();
		name=obj.nextLine();
		System.out.println("\nEnter the marks (PCMHE) :");
		System.out.print("\nPhysics : ");
		phy=obj.nextInt();
		System.out.print("\nChemistry : ");
		che=obj.nextInt();
		System.out.print("\nHindi : ");
		hin=obj.nextInt();
		System.out.print("\nEnglish : ");
		eng=obj.nextInt();
		System.out.print("\nMaths : ");
		mat=obj.nextInt();
	}

	void calPercent()
	{
		percent=(phy+che+mat+hin+eng)/5;
	}
}

class CollegeStudent extends Student
{
	int m1,m2,m3;
	Scanner obj=new Scanner(System.in);
	void getData()
	{

		System.out.print("\nEnter the rollno :");
		rollno=obj.nextInt();
		System.out.print("\nEnter the name :");
		obj.nextLine();
		name=obj.nextLine();
		System.out.println("\nEnter the marks :");
		System.out.print("\nm1 : ");
		m1=obj.nextInt();
		System.out.print("\nm2 : ");
		m2=obj.nextInt();
		System.out.print("\nm3 : ");
		m3=obj.nextInt();
	}

	void calPercent()
	{
		percent=(m1+m2+m3)/3;
	}
}

class Driver1
{
	public  static void main(String args[])
	{
         CollegeStudent c1=new CollegeStudent();
         SchoolStudent s1=new SchoolStudent();
         getEntry(c1);
         getEntry(s1);


	}
        static void getEntry(Student ref)
        {
			if(ref instanceof SchoolStudent)
			System.out.println("Working for School Student !");
			if(ref instanceof CollegeStudent)
			System.out.println("Working for College Student !");
			ref.getData();
			ref.calPercent();
			ref.display();
		}

}





