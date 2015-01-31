//switch statement example

import java.util.Scanner;
class SwitchCase
{
	public static void main(String args[])
	{
		Scanner obj=new Scanner(System.in);

		float a=0,b=0;
        float s=0;
        System.out.println("\nMENU");


        int n;
        int y=1;
        while(y!=0)
        {

        System.out.println("\n1:Addition\n2:Subtraction\n3:Division\n4:Multiplication");
        System.out.println("\nEnter the choice (1-4):");
		n=obj.nextInt();
		System.out.println("\nEnter the two numbers :");
		a=obj.nextFloat();
		b=obj.nextFloat();

		switch(n)
		        {
					case 1:s=a+b;
					break;
					case 2:s=a-b;
					break;
					case 3:s=a/b;
					break;
					case 4:s=a*b;
					break;
					default :
					System.out.println("\nInvalid entry !");
		         }
		System.out.println("\nResult = "+s);
		System.out.println("\nContinue (0:no  1:yes)?");
		y=obj.nextInt();
	    }
	}
}