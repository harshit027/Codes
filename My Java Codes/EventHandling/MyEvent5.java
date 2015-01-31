//windowActivated() and windowDeactivated()
//color and title changes on activation and deacvtivation

import java.awt.event.*;
import java.awt.*;
class MyEvent5 extends Frame
{
	public static void main(String args[])
	{
		MyEvent5 e1=new MyEvent5();

	}

	MyEvent5()
	{
		setSize(200,200);
        setTitle("Activated");
		setVisible(true);
		setBackground(Color.green);
		addWindowListener(new MyWindowAdapter());
	}

    class MyWindowAdapter extends WindowAdapter
    {
		public void windowActivated(WindowEvent we)
		{
			setBackground(Color.green);
			setTitle("Activated");
		}

		public void windowDeactivated(WindowEvent we)
		{
			setBackground(Color.red);
			setTitle("Deactivated");
		}
		public void windowClosing(WindowEvent we)
	    {
			System.exit(0);
		}
}

}