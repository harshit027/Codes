//creating a Choice list

import java.awt.*;
import java.awt.event.*;


class Choice1 extends Frame
{
	public static void main(String args[])
	{
		new Choice1();
	}
	 Choice1()
	 {
		 setSize(500,500);
		 setVisible(true);
         setLayout(null);
		 Choice ch=new Choice();
		 //ch.addItem("----------------");
		 ch.addItem("MALE");
		 ch.addItem("FEMALE");
	     ch.setBounds(200,200,0,0);
	     add(ch);
		 addWindowListener(new WindowAdapter()
		                                                  {
															  public void windowClosing(WindowEvent we)
															  {
																  System.exit(0);
															  }
														  });
	 }
 }
