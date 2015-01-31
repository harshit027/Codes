//creates windows wiht different attributes

import java.awt.Color;
import java.awt.Frame;
import java.util.Random;


class MyWindows1
{
	public static void main(String args[])
	{
		Random r=new Random();
		Frame f[]=new Frame[5];
		int x,y;
		for(int i=0;i<5;i++)
		{
			x=r.nextInt(600);
			y=r.nextInt(600);
		   f[i]=new Frame("MyWindow"+i);
		   f[i].setSize(200,200);
		   f[i].setVisible(true);
		   f[i].setLocation(x,y);
		   setColors(f[i],i);
	       try
	       {
			   Thread.sleep(1000);
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
