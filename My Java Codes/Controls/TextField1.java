//creating textfield

import java.awt.*;
import java.awt.event.*;

class TextField1 extends Frame
{
	public static void main(String args[])
	{
		new TextField1();
	}
	 TextField1()
	 {
		 setSize(500,500);
		 setVisible(true);
		 setBackground(Color.pink);
		 TextField tf=new TextField();
		 Label lb=new Label("Enter Name");
		 lb.setBounds(20,100,100,20);
		 tf.setBounds(100,100,100,20);
		// tf.setEchoChar('*');
		 add(tf);
		 add(lb);
		 addWindowListener(new WindowAdapter()
		                                                  {
															  public void windowClosing(WindowEvent we)
															  {
																  System.exit(0);
															  }
														  });
	 }
 }
