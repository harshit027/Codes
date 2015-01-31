//two threads in a single class

class MyThread3 extends Thread
{
	public static void main(String args[])
	{
		MyThread3 t=new MyThread3();
		for(int i=1;i<=5;i++)
		{
			System.out.println("Main thread working !");
			try
			{
				sleep(2000);
			}
			catch(Exception e)
			{}
		}
	}
	MyThread3()
	{
		start();
	}
	public void run()
	{
		for(int i=1;i<=5;i++)
				{
					System.out.println("Child thread working !");
					try
					{
						sleep(2000);
					}
					catch(Exception e)
			        {}
				}
			}
		}

