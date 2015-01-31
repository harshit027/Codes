//creating a Scrollbar

import java.awt.*;
import java.awt.event.*;

class Scrollbar1 extends Frame
{
	public static void main(String args[])
	{
		new Scrollbar1();
	}
	 Scrollbar1()
	 {
		 setSize(500,500);
		 setVisible(true);
         setLayout(null);
		 Scrollbar sb=new Scrollbar(Scrollbar.VERTICAL,0,20,100,200);
	     sb.setBounds(900,30,20,600);
	     add(sb);
		 addWindowListener(new WindowAdapter()
		                                                  {
															  public void windowClosing(WindowEvent we)
															  {
																  System.exit(0);
															  }
														  });
	 }
 }
