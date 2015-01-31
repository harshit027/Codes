 //reversing the entered String



import java.util.Scanner;
 class Myarray2
 {
    public static void main(String args[])
     {
		Scanner obj=new Scanner(System.in);
		int i,x;
        String s1;
        System.out.println("\nEnter a string ");
        s1=obj.next();
        x=s1.length();
        char a[]=new char[x];
        for(i=0;i<s1.length();i++,x--)
        a[i]=s1.charAt(x-1);

        System.out.println("\nthe reversed string is ");
        System.out.println(a);



     }
 }

