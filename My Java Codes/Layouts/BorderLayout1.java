//creating a BorderLayout

import java.awt.*;
import java.awt.event.*;
class BorderLayout1 extends Frame
{
	public static void main(String args[])
	{
		new BorderLayout1();
	}

	BorderLayout1()
	{
		setSize(500,500);

		//setResizable(false);
		BorderLayout bl=new BorderLayout(50,50);
		setLayout(bl);
		Button bt1=new Button("Click 1");
        Button bt2=new Button("Click 2");
        Button bt3=new Button("Click 3");
        Button bt4=new Button("Click 4");
        Button bt5=new Button("Click 5");

        addWindowListener(new WindowAdapter()
                                                        {
															public void windowClosing(WindowEvent we)
															{
																System.exit(0);
															}
														});
		add(bt1,"North");
		add(bt2,BorderLayout.SOUTH);
		add(bt3,"Center");
		add(bt4,"East");
		add(bt5,"West");
		setVisible(true);
	}
}
