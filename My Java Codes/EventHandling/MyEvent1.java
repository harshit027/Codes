//changes the window color on click

import java.awt.event.*;
import java.awt.*;
class MyEvent1 extends Frame implements MouseListener
{
	public static void main(String args[])
	{
		MyEvent1 e1=new MyEvent1();

	}
	int n=0;
	MyEvent1()
	{
		setSize(200,200);
		setVisible(true);
		setTitle("MyEvent1");
		addMouseListener(this);
	}
	public void mouseClicked(MouseEvent me)
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
	public void mouseReleased(MouseEvent me)
	{
	}
	public void mousePressed(MouseEvent me)
	{
	}
	public void mouseEntered(MouseEvent me)
	{
	}
	public void mouseExited(MouseEvent me)
	{
	}
}