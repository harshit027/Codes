package mypack;

import java.util.Scanner;

public class Car
{
	private String company;
	private int modelno;
	private double price;

	public Car()
	{
		company="Maruti";
		modelno=800;
		price=2.5;
	}
	public Car(String comp,int model,double prc)
	{
		company=comp;
		modelno=model;
		price=prc;
	}

	public void getCar()
	{
		Scanner obj=new Scanner(System.in);
		System.out.print("Enter the company name : ");
		company=obj.nextLine();
		System.out.print("Enter the model number : ");
		modelno=obj.nextInt();
		System.out.print("Enter the price : ");
		price=obj.nextDouble();
	}

	public void showCar()
	{
		System.out.println("Company : "+company+"\nModel number : "+modelno+"\nPrice : "+price);
	}
}



