class MainThread1
{
	public static void main(String args[])
	{
	try
	{
	    CommonResource ref=new CommonResource();
	    Thread11 t1=new Thread11(ref);
	    Thread22 t2=new Thread22(ref);
	    Thread33 t3=new Thread33(ref);
	     t1.join();
	     t2.join();
	     t3.join();
	 }
	 catch(Exception e)
	 {
		 e.toString();
	 }
 }
 }

 class Thread11 extends Thread
 {
	 CommonResource ref;
	 Thread11(CommonResource ref)
	 {
		 this.ref=ref;
		 start();
	 }

	 public void run()
	 {
		 for(int i=0;i<3;i++)
		 {
			 ref.printThread11();
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

	class Thread22 extends Thread
	 {
		 CommonResource ref;
		 Thread22(CommonResource ref)
		 {
			 this.ref=ref;
			 start();
		 }

		 public void run()
		 {
			 for(int i=0;i<3;i++)
			 {
				ref.printThread22();
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

	 class Thread33 extends Thread
	  {
	 	 CommonResource ref;
	 	 Thread33(CommonResource ref)
	 	 {
	 		 this.ref=ref;
	 		 start();
	 	 }

	 	 public void run()
	 	 {
	 		 for(int i=0;i<3;i++)
	 		 {
	 			ref.printThread33();
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

	 class CommonResource
	 {
		 private boolean flag1=true,flag2=true;

		 synchronized public void printThread11()
		 {
			 if(flag1==true&&flag2==true)
			 {
				 System.out.println("Thread11 working");
				 flag1=true;
				 flag2=false;
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

	     synchronized public void printThread22()
		 {
		 	 if(flag1==true&&flag2==false)
		 	 {
		 		 System.out.println("Thread22 working");
		 		 flag1=false;
		 		 flag2=true;
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

		 synchronized public void printThread33()
		 {
		 	 if(flag1==false&&flag2==true)
		 	 {
		 		 System.out.println("Thread33 working\n");
		 		 flag1=true;
		 		 flag2=true;
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