import java .util.Scanner;

class Resource
{
	private  int a=0,b=0,c=0;
	boolean flag1=true,flag2=true;
    int n;

	synchronized public void inputFun()
	{
		if(flag1==true && flag2==true)
		{
		   Scanner obj=new Scanner(System.in);
		   System.out.println("Enter the number for addition :");
		   a=obj.nextInt();
		   b=obj.nextInt();
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

   synchronized public void calculator()
   {
	   if(flag1==true&&flag2==false)
	   {
		   c=a+b;
		   System.out.println("Addition Performed !");
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

	   synchronized public void outputFun()
	   {
		   if(flag1==false&&flag2==true)
		   {
			  System.out.println("Sum of "+a+" and "+b+" is "+c);
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
   synchronized int getN()
   {
	   return n;
   }
   synchronized void setN(int n)
   {
	   this.n=n;
   }

}

class InputThread extends Thread
{
	Resource r;
	InputThread(Resource r)
	{
		this.r=r;
		start();
	}
	public void run()
	{
        int x;
		for(int i=0;i<5;i++)
		{
          x=r.getN();

           if(x!=0) i--;
           r.inputFun();
		   r.setN(1);


		   try
		   {
		    	sleep(1000);
		    }
		    catch(Exception e)
		    {
		    	e.toString();
			}
		}
	}
}

class CalculateThread extends Thread
{
	Resource r;
	CalculateThread(Resource r)
	{
		this.r=r;
		start();
	}
	public void run()
	{
		int x;
		for(int i=0;i<5;i++)
		{
			x=r.getN();
			if(x!=1)
			i--;
			r.calculator();
	    	r.setN(2);

	    	try
	    	{
	    		sleep(1000);
	    	}
	    	catch(Exception e)
	    	{
	    		e.toString();
	    	}
	     }
     }
}

class OutputThread extends Thread
{
	Resource r;
	OutputThread(Resource r)
	{
		this.r=r;
		start();
	}
	public void run()
	{
		int x;
		for(int i=0;i<5;i++)
		{
			x=r.getN();

			if(x!=2)
			i--;

            r.setN(0);
    		r.outputFun();

    		try
    		{
    			sleep(1000);
    		}
    		catch(Exception e)
    		{
    			e.toString();
    		}
		}
	}
}

class MyAdder1
{
	public static void main(String args[])
	{
		try
		{
		   Resource cr=new Resource();
		   InputThread i=new InputThread(cr);
		   CalculateThread c=new CalculateThread(cr);
		   OutputThread o=new OutputThread(cr);

		   i.join();
		   c.join();
		   o.join();
	     }
	     catch(Exception e)
	     {
			 e.toString();
		 }
	 }
 }