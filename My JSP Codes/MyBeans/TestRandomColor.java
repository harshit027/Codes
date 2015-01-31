//import matrix.*;
import java.util.*;
import java.awt.*;
import javax.swing.*;

class TestRandomColor extends JFrame
{
	TestRandomColor()
	{
		setSize(400,400);
		RandomColor rndColor=new RandomColor();
		setVisible(true);
		while(true)
		{
			rndColor.setRandomColor();
		    getContentPane().setBackground(rndColor.getRandomColor());
		    try
		    {
				Thread.sleep(1000);
			}
			catch(Exception ex)
			{
				System.out.println("Error : "+ex);
			}
	    }

	}

	public static void main(String args[])
	{
		new TestRandomColor();
	}
}