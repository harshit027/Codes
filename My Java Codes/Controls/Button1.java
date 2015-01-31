//creating a button

import java.awt.*;
import java.awt.event.*;

class Button1 extends Frame implements ActionListener
{
    Button bt=new Button("Click here");
	Button1()
	{
		setSize(500,500);
		setVisible(true);
		setTitle("Button Example");


		addWindowListener(new WindowAdapter()
		                                                 {
															 public void windowClosing(WindowEvent we)
															 {
																 System.exit(0);
															 }
														 });


		setLayout(null);
		setForeground(Color.red);
        bt.setBackground(Color.yellow);
		bt.setBounds(50,50,100,70);
        bt.addActionListener(this);
		add(bt);
	}

	public void actionPerformed(ActionEvent ae)
	{
		Button ref=(Button)ae.getSource();
		if(ref==bt)
		{
			setTitle("Button Activated");
		}
	}
	public static void main(String args[])
	{
		new Button1();
	}
}
