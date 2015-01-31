 //using static members ,



import java.util.Scanner;
 class Staticmem
 {
	 static int a,b,c=0; //static functions can access only static members
	 int d,e,f=0;        //non stat
    public static void main(String args[]) //static function
     {

		 Scanner obj=new Scanner(System.in);

		 System.out.println("\nEnter the numbers for addition :");
		 a=obj.nextInt();
		 b=obj.nextInt();
		 c=a+b;
		 System.out.println("\nthe sum is :"+c);

		 Staticmem t=new Staticmem(); //in place of making static you can access members by making objects
		 System.out.println("\nEnter numbers for subtraction :");
		 t.d=obj.nextInt();
		 t.e=obj.nextInt();
		 t.f=t.d-t.e;
		 System.out.println("\nthe differnce is :"+t.f);



     }
 }

