//catch the window if you can

import java.awt.event.*;
import java.awt.*;

class MyEvent7 extends Frame
{
	public static void main(String args[])
	{
		new MyEvent7(0,0,0);
	}

	MyEvent7(int x,int y,int i)
	{

		Color []c=new Color[]{Color.red,Color.blue,Color.green,Color.orange,Color.yellow,Color.pink,Color.magenta};
		setSize(200,200);
		setVisible(true);
		setLocation(x,y);
		setResizable(false);
		setBackground(c[i]);
		addMouseListener(new MyMouseAdapter());
		addWindowListener(new WindowAdapter()
		                                                 {
															 public void windowClosing(WindowEvent we)
															 {
																 System.exit(0);
															 }
														 });

	}

	class MyMouseAdapter extends MouseAdapter
	{
		public void mouseEntered(MouseEvent me)
		{
			java.util.Random rnd=new java.util.Random();
			int x=rnd.nextInt(600);
			int y=rnd.nextInt(600);
			int i=rnd.nextInt(6);
			setVisible(false);
			new MyEvent7(x,y,i);
		}
	}
}