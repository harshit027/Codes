//demonstration of array

import java.util.Scanner;
class Myarray
{
	public static void main(String args[])
	{
		Scanner obj=new Scanner(System.in);
		int a[]=new int[5];
		System.out.println("\nenter the elements of array :");
		for(int i=0;i<5;i++)
		a[i]=obj.nextInt();
		System.out.println("\nthe elements you entered are ...");
		for(int j=0;j<5;j++)
		System.out.println("a["+j+"] :"+a[j]);


	}
}