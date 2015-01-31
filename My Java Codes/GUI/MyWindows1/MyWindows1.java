//prints windows using threads

import java.awt.Color;
import java.awt.Frame;
import java.util.Random;


class MyWindows1
{
	public static void main(String args[])
	{
		try
		{

		   Common cr=new Common();
		   WindowThread1 w1=new WindowThread1(cr);
		   WindowThread2 w2=new WindowThread2(cr);

		   w1.join();
		   w2.join();
	   }
	   catch(Exception e)
	   {
		   e.toString();
	   }
   }

}

class WindowThread1 extends Thread
{
	Common ref;
	WindowThread1(Common ref)
	{
		this.ref=ref;
		start();
	}

	public void run()
    {
		Random r=new Random();
		Frame f[]=new Frame[5];
		int x,y;
		for(int i=0;i<5;i++)
		{
			ref.WindowThread1Fun();
			x=r.nextInt(600);
			y=r.nextInt(600);
		    f[i]=new Frame("MyWindow"+(2*i+1));
		    f[i].setSize(200,200);
		    f[i].setVisible(true);
		    f[i].setLocation(x,y);
		    setColors(f[i],i);
	        try
	        {
     		   Thread.sleep(2000);
     		   f[i].setVisible(false);
	   	    }
		    catch(Exception e)
		    {
			   e.toString();
		    }
	   }
   }

	 static void setColors(Frame fref,int x)
	    {

	 	   switch(x)
	 	   {
	 		   case 0:
	 		   fref.setBackground(Color.red);
	 		   break;
	 		   case 1:
	 		   fref.setBackground(Color.blue);
	 		   break;
	 		   case 2:
	 		   fref.setBackground(Color.green);
	 		   break;
	 		   case 3:
	 		   fref.setBackground(Color.pink);
	 		   break;
	 		   case 4:
	 		   fref.setBackground(Color.orange);

	 	   }
       }
   }

	class WindowThread2 extends Thread
	{
		Common ref;
		WindowThread2(Common ref)
		{
			this.ref=ref;
			start();
		}

		public void run()
	    {
			Random r=new Random();
			Frame f[]=new Frame[5];
			int x,y;
			for(int i=0;i<5;i++)
			{
				ref.WindowThread2Fun();
				x=r.nextInt(600);
				y=r.nextInt(600);
			    f[i]=new Frame("MyWindow"+(2*i));
			    f[i].setSize(200,200);
			    f[i].setVisible(true);
			    f[i].setLocation(x,y);
			    setColors(f[i],i);
		        try
		        {
	     		   Thread.sleep(2000);
	     		   f[i].setVisible(false);
		   	    }
			    catch(Exception e)
			    {
				   e.toString();
			    }
		   }
	   }

		 static void setColors(Frame fref,int x)
		    {

		 	   switch(x)
		 	   {
		 		   case 0:
		 		   fref.setBackground(Color.yellow);
		 		   break;
		 		   case 1:
		 		   fref.setBackground(Color.cyan);
		 		   break;
		 		   case 2:
		 		   fref.setBackground(Color.magenta);
		 		   break;
		 		   case 3:
		 		   fref.setBackground(Color.gray);
		 		   break;
		 		   case 4:
		 		   fref.setBackground(Color.black);

		 	   }
	       }
   }

class Common
{
	boolean flag=true;

	synchronized public void WindowThread1Fun()
	{
		if(flag==true)
		{
		   System.out.println("WindowThread1Fun working !");
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

	synchronized public void WindowThread2Fun()
		{
			if(flag==false)
			{
			   System.out.println("WindowThread2Fun working !");
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
	}
}

