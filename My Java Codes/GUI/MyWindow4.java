//4th way to create a window

import javax.swing.JFrame;


class MyWindow4 extends JFrame
{
	public static void main(String args[])
	{

       MyWindow4 w=new MyWindow4();
		w.setSize(400,400);
		w.setVisible(true);
		w.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);




	}

}