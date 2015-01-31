//some more threads
import java.util.Random;

class MyThread2
{
	public static void main(String args[])
	{
		ChildThread2 obj=new ChildThread2();
		for(int i=1;i<=5;i++)
		{
			System.out.println("Main thread working !");
			try
			{
				Thread.sleep(2000);
			}
			catch(Exception e)
			{
			}
		}
	}
}

class ChildThread2 extends Thread
{
	Random r=new Random();
	ChildThread2()
	{
		start();
	}
	public void run()
	{
		int n;
		for(int i=1;i<=5;i++)
		{
			n=r.nextInt(50);
			System.out.println("Random integer = "+n);
			try
			{
				sleep(2000);
			}
			catch(Exception e)
			{
			}
		}
	}
}