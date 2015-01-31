import java.util.Scanner;

abstract class Shape                                   //class made abstract
{
	double a,b,c;

	abstract void getData();                         //abstract function defined in sub class
	abstract void area();

	void showArea()
	{
		System.out.println("Area = "+c);
	}


}

class Triangle extends Shape
{
	void getData()                                     //defining getData() int Triangle
	{
		Scanner obj=new Scanner(System.in);
		System.out.println("Enter the length of base and height :");
		a=obj.nextDouble();
		b=obj.nextDouble();
	}

	void area()                                            //defining area() in Triangle
	{
		c=0.5*a*b;
	}
}

class Square extends Shape
{
	void getData()                                     //defining getData() in Square
	{
		Scanner obj=new Scanner(System.in);
		System.out.println("Enter the side of square :");
		a=obj.nextDouble();
	}

	void area()                                           //defining area() in Square
	{
		c=a*a;
	}
}

class Driverclass
{
	public static void main(String args[])
	{

		Triangle t=new Triangle();
		Square s=new Square();
		t.getData();
		t.area();
		t.showArea();
	}
}
