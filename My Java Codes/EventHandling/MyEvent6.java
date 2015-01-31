//windowClosed() and keyTyped()
//try closing the window until you succeed

import java.util.Random;
import java.awt.event.*;
import java.awt.*;
class MyEvent6 extends Frame
{
	public int x,y;
	public static void main(String args[])
	{
		MyEvent6 e1=new MyEvent6(0,0);

	}

	MyEvent6(int x1,int y1)
	{
		Random rnd=new Random();
        Color []c=new Color[]{Color.red,Color.blue,Color.green,Color.orange,Color.yellow,Color.pink,Color.magenta};
		setSize(200,200);
		int i=rnd.nextInt(6);
        setTitle("Press q to quit");
		setVisible(true);
		setBackground(c[i]);
		setLocation(x1,y1);
        addKeyListener(new MyKeyAdapter());
		addWindowListener(new MyWindowAdapter());
	}

    class MyWindowAdapter extends WindowAdapter
    {

		public void windowClosing(WindowEvent we)
	    {
           Random rnd=new Random();
           x=rnd.nextInt(600);
           y=rnd.nextInt(600);
		   setVisible(false);
		   new MyEvent6(x,y);
		}
	}
	class MyKeyAdapter extends KeyAdapter
	{
		public void keyPressed(KeyEvent ke)
		{
			if(ke.getKeyChar()=='q')
			System.exit(0);
		}
	}


}

