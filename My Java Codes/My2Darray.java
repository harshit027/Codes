//demonstration of two 2 array

 import java.util.Scanner;
 class My2Darray
 {
    public static void main(String args[])
     {
      Scanner s=new Scanner(System.in);
      int a[][]=new int[3][3];
      int sum=0,i,j;
      System.out.println("\nenter the elements of two-d array (integers):");
      for(i=0;i<3;i++)
      {
		  for(j=0;j<3;j++)

          a[i][j]=s.nextInt();
	  }
System.out.println("\nThe elments of two-d array are ..");

      for(i=0;i<3;i++)
      {
		  for(j=0;j<3;j++)
		  System.out.println("a["+i+"]["+j+"] :"+a[i][j]);

      }
  }
 }

