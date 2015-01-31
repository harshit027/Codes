//creating a GridLayout

import java.awt.*;
import java.awt.event.*;
class GridLayout1 extends Frame
{
	public static void main(String args[])
	{
		new GridLayout1();
	}

	GridLayout1()
	{
		setSize(500,500);

		//setResizable(false);

		setLayout(new GridLayout(3,3));
		Button bt1=new Button("Click 1");
        Button bt2=new Button("Click 2");
        Button bt3=new Button("Click 3");
        Button bt4=new Button("Click 4");
        addWindowListener(new WindowAdapter()
                                                        {
															public void windowClosing(WindowEvent we)
															{
																System.exit(0);
															}
														});
		add(bt1);
		add(bt2);
		add(bt3);
		add(bt4);
		setVisible(true);
	}
}
