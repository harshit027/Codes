//creating textarea

import java.awt.*;
import java.awt.event.*;

class TextArea1 extends Frame
{
	public static void main(String args[])
	{
		new TextArea1();
	}
	 TextArea1()
	 {
		 setSize(500,500);
		 setVisible(true);
		 setBackground(Color.pink);
		 TextArea ta=new TextArea();


		 ta.setBounds(100,100,200,100);
		 add(ta);

		 addWindowListener(new WindowAdapter()
		                                                  {
															  public void windowClosing(WindowEvent we)
															  {
																  System.exit(0);
															  }
														  });
	 }
 }
