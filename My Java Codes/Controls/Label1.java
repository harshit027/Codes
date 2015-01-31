//creating labels

import java.awt.*;
import java.awt.event.*;

class Label1 extends Frame
{
	Label1()
	{
		setSize(500,500);
		setVisible(true);
		setTitle("Label Example");

		addWindowListener(new WindowAdapter()
		                                                 {
															 public void windowClosing(WindowEvent we)
															 {
																 System.exit(0);
															 }
														 });

		Label lb=new Label("Enter name",Label.LEFT);
		setLayout(null);
		setForeground(Color.red);
		lb.setBounds(20,20,100,100);
		lb.setAlignment(Label.CENTER);

		add(lb);
	}
	public static void main(String args[])
	{
		new Label1();
	}
}
