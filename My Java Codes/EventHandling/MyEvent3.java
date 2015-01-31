//close window using default close operation

import java.awt.event.*;
import java.awt.*;
class MyEvent3 extends Frame implements WindowListener
{
	public static void main(String args[])
	{
		MyEvent3 e1=new MyEvent3();

	}
	int n=0;
	MyEvent3()
	{
		setSize(200,200);
		setTitle("MyEvent3");
		setVisible(true);
		addWindowListener(this);


	}
	public void windowOpened(WindowEvent we)
	{
	}
	public void windowClosed(WindowEvent we)
	{
	}
	public void windowClosing(WindowEvent we)
	{
		System.exit(0);
	}
	public void windowActivated(WindowEvent we)
	{
	}
	public void windowDeactivated(WindowEvent we)
	{
	}
	public void windowIconified(WindowEvent we)
		{
	}
	public void windowDeiconified(WindowEvent we)
		{
	}


}