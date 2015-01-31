//creating Radio Button

import java.awt.*;
import java.awt.event.*;

class RadioButton1 extends Frame
{


	public static void main(String args[])
	{
		new RadioButton1();
	}
	 RadioButton1()
	 {
		 setSize(500,500);
		 setVisible(true);
		 setBackground(Color.pink);
         CheckboxGroup cbg=new CheckboxGroup();
    	 Checkbox cb=new Checkbox("Tick here",cbg,false);
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
