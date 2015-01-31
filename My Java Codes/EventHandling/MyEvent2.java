//changes the window color on dragging the mouse on window

import java.awt.event.*;
import java.awt.*;
class MyEvent2 extends Frame implements MouseListener
{
	public static void main(String args[])
	{
		MyEvent2 e1=new MyEvent2();

	}
	int n=0;
	MyEvent2()
	{
		setSize(200,200);
		setVisible(true);
		setTitle("MyEvent2");
		addMouseListener(this);
		setResizable(false);
		addWindowListener(new WindowAdapter(){
			                                                                                  public void windowClosing(WindowEvent we)
			                                                                                  {
																								  System.exit(0);
																							  }
																						  });


	}
	public void mouseClicked(MouseEvent me)
	{
	}
	public void mouseReleased(MouseEvent me)
	{
	}
	public void mousePressed(MouseEvent me)
	{
	}
	public void mouseEntered(MouseEvent me)
	{
		switch(n)
				{
					case 0:
					setBackground(Color.red);
					break;
					case 1:
					setBackground(Color.blue);
					break;
					case 2:
					setBackground(Color.green);
					break;
					case 3:
					setBackground(Color.orange);
					break;
					case 4:
					setBackground(Color.yellow);
					break;
				}
				n++;
				if(n>4)
		n=0;
	}
	public void mouseExited(MouseEvent me)
	{
	}


}