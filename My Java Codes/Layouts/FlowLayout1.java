//creating a FlowLayout

import java.awt.*;
import java.awt.event.*;
class FlowLayout1 extends Frame
{
	public static void main(String args[])
	{
		new FlowLayout1();
	}

	FlowLayout1()
	{
		setSize(500,500);

		//setResizable(false);
		FlowLayout fl=new FlowLayout(FlowLayout.LEFT);
		setLayout(fl);
		Button bt1=new Button("Click 1");
        Button bt2=new Button("Click 2");
        Button bt3=new Button("Click 3");
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
		setVisible(true);
	}
}
