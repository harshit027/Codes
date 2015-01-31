//creation of  threads by implementing Runnable interface

class MyThread1
{
	public static void main(String args[])
	{

 	    ChildThread1 obj=new ChildThread1();
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

class ChildThread1 implements Runnable
{
	Thread t;

	ChildThread1()
	{
		t=new Thread(this);  // 'this' shows that run() function is in same class
		t.start();
	}
	public void run()
	{
		for(int i=1;i<=5;i++)
		{
			System.out.println("Child thread working !");
			try
			{
				t.sleep(2000);
			}
			catch(Exception e)
			{
			}
		}
	}
}

