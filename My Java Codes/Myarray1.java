 //reversing the entered array


 import java.util.Scanner;
 class Myarray1
 {
    public static void main(String args[])
     {
      Scanner s=new Scanner(System.in);
      int a[]=new int[6];
      int i,temp;
      for(i=0;i<6;i++)
      a[i]=i*2;
      System.out.println("\nEntered array...");
      for(i=0;i<6;i++)
      System.out.println("a["+i+"] :"+a[i]);

      for(i=0;i<3;i++)
      {

         temp=a[i];
         a[i]=a[5-i];
         a[5-i]=temp;
	 }
	 System.out.println("The reversed array is ...");
	 for(i=0;i<6;i++)
	System.out.println("a["+i+"] :"+a[i]);
     }
 }

