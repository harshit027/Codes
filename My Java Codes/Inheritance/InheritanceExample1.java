import java.util.Scanner;
abstract class Student {
	int rollno;
	String name;
	double percentage;
	abstract void getdata();
	abstract void calculatePercent();
	void show() {
		System.out.println("Roll No :"+rollno);
		System.out.println("Name :"+name);
		System.out.println("Percentage :"+percentage);
	}
}

class SchoolStudent extends Student {
	int phy, chem, maths, hindi, english;
	void getdata() {
		Scanner obj = new Scanner(System.in);
		System.out.print("Enter Roll No :");
		rollno = obj.nextInt();
		System.out.print("Enter Name :");
		obj.nextLine();
		name = obj.nextLine();
		System.out.println("Enter Marks of (PCMHE) :");
		phy = obj.nextInt();
		chem = obj.nextInt();
		maths = obj.nextInt();
		hindi = obj.nextInt();
		english = obj.nextInt();
	}
	void calculatePercent() {
		percentage = (phy+chem+maths+hindi+english)/5;
	}
}

class CollegeStudent extends Student {
	String degree;
	int m1, m2, m3;
	void getdata() {
		Scanner obj = new Scanner(System.in);
		System.out.print("Enter Roll No :");
		rollno = obj.nextInt();
		System.out.print("Enter Name :");
		obj.nextLine();
		name = obj.nextLine();
		System.out.print("Enter Degree :");
		degree = obj.nextLine();
		System.out.println("Enter Marks of 3 subjects :");
		m1 = obj.nextInt();
		m2 = obj.nextInt();
		m3 = obj.nextInt();
	}
	void calculatePercent() {
		percentage = (m1+m2+m3)/3;
	}
}

class InheritanceExample1 {
	public static void main(String args[]) {
		SchoolStudent ss = new SchoolStudent();
		CollegeStudent cs = new CollegeStudent();
		callfunctions(ss);
		callfunctions(cs);
	}
	static void callfunctions(Student ref) {
		if(ref instanceof SchoolStudent) {
			System.out.println("Working for School Student ...\n");
		}
		else {
			System.out.println("Working for College Student ...\n");
		}
		ref.getdata();
		ref.calculatePercent();
		ref.show();
	}
}