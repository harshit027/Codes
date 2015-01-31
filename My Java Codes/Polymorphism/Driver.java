import java.util.Scanner;

class Shape
{
	double a,b,c;

	void getData()
	{
		Scanner obj=new Scanner(System.in);
		System.out.println("Enter the parameters :");
		a=obj.nextDouble();
		b=obj.nextDouble();
	}
	void showArea()
	{
		System.out.println("Area = "+c);
	}
	void area()
	{
		c=a*b;
	}
}

class Triangle extends Shape
{
	void getData()                                     //overriding getData() int Triangle
	{
		Scanner obj=new Scanner(System.in);
		System.out.println("Enter the length of base and height :");
		a=obj.nextDouble();
		b=obj.nextDouble();
	}

	void area()                                            //overriding area() in Triangle
	{
		c=0.5*a*b;
	}
}

class Square extends Shape
{
	void getData()                                     //overriding getData() in Square
	{
		Scanner obj=new Scanner(System.in);
		System.out.println("Enter the side of square :");
		a=obj.nextDouble();
	}

	void area()                                           //overriding area() in Square
	{
		c=a*a;
	}
}

class Driver
{
	public static void main(String args[])
	{
		Shape s=new Shape();
		Triangle t=new Triangle();
		Square s1=new Square();
		s1.getData();
		s1.area();
		s1.showArea();
	}
}
