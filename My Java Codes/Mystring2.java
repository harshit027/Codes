 //checking the email as valid or invalid



import java.util.Scanner;
 class Mystring2
 {
    public static void main(String args[])
     {
		Scanner obj=new Scanner(System.in);
		int i,x,n=2,dot=0;
        String s1;
        System.out.println("\nEnter a string ");
        s1=obj.next();
        x=s1.length();
        char a;
        for(i=0;i<x;i++)
        {
			a=s1.charAt(i);
			if(a=='-')
			n=1;

		}
		if(n==1)
		{
		    System.out.println("\nInvalid email address !");
		    System.exit(0);
		}

		else
		if(n==2)
		{
		for(i=0;i<x;i++)
		{
			a=s1.charAt(i);
			if(a=='@')
			{
				n=0;
			}
		}
		if(n==0)
		{
			System.out.println("\nValid email address!");
			System.exit(0);
		}
	    }

     }
 }

