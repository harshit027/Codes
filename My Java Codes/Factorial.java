// this code works in command interpreter

class Factorial
{
	public static void main(String args[])
	{
		if(args.length!=1)
		{
			System.out.println("\nInvalid arguments passed , Try again !");
			return;
		}
		int n =  Integer.parseInt(args[0]);
		int fact=1;
		int i=n;
		while(n>=1)
		{
			fact=fact*n--;
		}
		System.out.println("Factorial of "+i+" = "+fact);
	}
}
