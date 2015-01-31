//1st way to create a window

import java.awt.Frame;

class MyWindow1 extends Frame
{
	public static void main(String args[])
	{
		MyWindow1 w=new MyWindow1();
		w.setSize(400,400);
		w.setVisible(true);
		w.setResizable(false);



	}

}