package mypack;

import java.util.Scanner;
public class Vehicle
{
	private String color;
	private int modelno;

	public Vehicle()
	{
		color="red";
		modelno=101;
	}

	public void getVehicle()
	{
		Scanner obj=new Scanner(System.in);
		System.out.print("Enter the color of vehicle : ");
		color=obj.nextLine();

		System.out.print("Enter the model number : ");
		modelno=obj.nextInt();
	}
	public void showVehicle()
	{
		System.out.println("\nModel Number : "+modelno);
		System.out.println("\nColor : "+color);
	}
}