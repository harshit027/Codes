//2nd  way to create a window

import java.awt.Frame;

class MyWindow2 extends Frame
{
	public static void main(String args[])
	{
		new MyWindow2();

	}
	MyWindow2()
	{
	    setSize(400,400);
		setVisible(true);
	}
}