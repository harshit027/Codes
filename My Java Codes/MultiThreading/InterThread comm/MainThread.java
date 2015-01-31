//resource sharing by threads
//"Thread1" and "Thread2" shared common resource "Common ref" with inter thread communication
//This is done to make sure that setN() and getN() will work sequentially,,,,,

import java.util.Random;

class Thread1 extends Thread
{
	Common ref;
	Thread1(Common ref)
	{
		this.ref=ref;
		start();
	}
	public void run()
	{
		Random r=new Random();
		for(int i=0;i<5;i++)
		{
			int n=r.nextInt(10);
			System.out.println("\nThread1 set n = "+n);
			ref.setN(n);
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

class Thread2 extends Thread
{
	Common ref;
	Thread2(Common ref)
	{
		this.ref=ref;
		start();
	}
	public void run()
	{
		for(int i=0;i<5;i++)
		{
			int n=ref.getN();
			if(n==-1)
			i--;
			System.out.println("Thread2 recieved n = "+n);
			while(n-->=1)
			{
				System.out.print("+");

			}
			System.out.println("");
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

class MainThread
{
	public static void main(String args[])
	{
		try
		{
			Common cr=new Common();
			Thread t1=new Thread1(cr);
			Thread t2=new Thread2(cr);
			t1.join();
			t2.join();
		}
		catch(Exception e)
		{
			e.toString();
		}
	}
}

class Common
{
	private int n;
	private boolean flag=true;
	synchronized public int getN()
	{
		//System.out.println("getN()");
		int t=-1;
		if(flag==false)
		{
			t=n;
			flag=true;
			notify();
		}
		else
		{
			try
			{
				wait();
			}
			catch(Exception e)
			{
				e.toString();
			}

		}
		return t;
	}

	synchronized public void setN(int n)
	{
		//System.out.println("setN()");
		if(flag==true)
		{
		   this.n=n;
		   flag=false;
		   notify();
	   }
	   else
	   {
		   try
		   {
			   wait();
		   }
		   catch(Exception e)
		   {
			   e.toString();
		   }
	   }
	}
}