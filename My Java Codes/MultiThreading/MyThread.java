//creation of threads by inheriting Thread class


class MyThread
{
	public static void main(String args[])
	{
		ChildThread obj=new ChildThread();
		for(int i=0;i<=10;i++)
		{
			System.out.println("Main Thread Working !");
			try
			{
				Thread.sleep(2000); //waiting for main thread
			}
			catch (Exception e)
			{
			}
		}
	}
}

class ChildThread extends Thread
{
	ChildThread()
	{
		start();
	}
	public void run()
	{
		for(int i=1;i<=10;i++)
		{
			System.out.println("Child Thread Working !");
			try
			{
				sleep(4000);  //waiting time for child thread
			}
			catch(Exception e)
			{
			}
		}
	}
}