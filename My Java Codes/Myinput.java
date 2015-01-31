//taking inputs from keyboard

import java.util.Scanner;
import java.io.*;
class Myinput{
	public static void main(String args[])throws IOException
	{
	//declaring an object for taking input from keyboard
	Scanner obj=new Scanner(System.in);

	//Entering a string
	System.out.println("\nEnter a string !");
	String s=obj.nextLine();
	System.out.println("you have entered "+ s);

	//entering a word
	System.out.println("\nEnter a word !");
	String w=obj.next();

	//entering an integer
	System.out.println("\nEnter an integer !");
	int n=obj.nextInt();

	//entering a float
	System.out.println("\nEnter a floating point number !");
	float f=obj.nextFloat();

	//Printing the inputs
	System.out.println("\nThe inputs are .....");
	System.out.println("\nWord : "+w+"\nInteger : "+n+"\nFloat : "+f);


}
}