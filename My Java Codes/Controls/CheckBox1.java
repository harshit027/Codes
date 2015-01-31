//creating checkboxfield

import java.awt.*;
import java.awt.event.*;

class CheckBox1 extends Frame
{
	public static void main(String args[])
	{
		new CheckBox1();
	}
	 CheckBox1()
	 {
		 setSize(500,500);
		 setVisible(true);
		 setBackground(Color.pink);
         setLayout(null);
		 Checkbox cb=new Checkbox("Tick Here");
		 cb.setBounds(100,100,200,200);
		 add(cb);

		 addWindowListener(new WindowAdapter()
		                                                  {
															  public void windowClosing(WindowEvent we)
															  {
																  System.exit(0);
															  }
														  });
	 }
 }
