
//finds the factorial of a number


import java.util.Scanner;
 class Factorial1
 {

    public static void main(String args[])
     {
		 Scanner obj=new Scanner(System.in);
		 long  f;
		 int x;
         System.out.println("\nEnter the number whose factorial is to be found out :");

         x=obj.nextInt();
		 Factorial1 t=new Factorial1();
		 f=t.factorial(x);
		 System.out.println("\nThe factorial of "+x+" is "+f);
	 }


		 long factorial(int n)
		 {

			 long fact=1;

			 while(n>1)
			 fact=fact*n--;
			 return fact;
		 }


 }

