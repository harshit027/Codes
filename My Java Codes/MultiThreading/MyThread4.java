//some more threads

import java.util.Random;
class MyThread4 extends Thread
{
	public static void main(String args[])
	{
        MyThread4 t=new MyThread4();
		char a[]=new char[]{'a','b','c','d','e','f','g','h','i','j','h','i'};
        Random r=new Random();
        int n1,n2,n3,n4;
        for(int i=0;i<5;i++)
        {
            n1=r.nextInt(11);
            n2=r.nextInt(11);
            n3=r.nextInt(11);
            n4=r.nextInt(11);
		    System.out.print(a[n1]);
		    System.out.print(a[n2]);
		    System.out.print(a[n3]);
		    System.out.println(a[n4]);
		    try
		    {
				sleep(2000);
			}
			catch(Exception e)
			{
				e.toString();
			}
		}
	}
	Random r1=new Random();

	MyThread4()
	{
		start();
	}
	public void run()
	{

		for(int i=0;i<5;i++)
		{
			int n=r1.nextInt(20);
			System.out.println(n);
		    try
		    {
				sleep(2000);
			}
		catch(Exception e)
			{
				e.toString();
			}
		}
	}
}