//ten windpws attached with each other

import java.awt.*;

class MyWindows extends Frame
{
	public static void main(String args[])
	{
		Color c[]=new Color[]{Color.red,Color.blue,Color.gray,Color.green,Color.yellow,Color.pink,Color.orange,Color.magenta,Color.cyan,Color.white};
		MyWindows w[]=new MyWindows[10];
		for(int i=0;i<10;i++)
		w[i]=new MyWindows();


		for(int i=0;i<10;i++)
		{
		   w[i].setSize(200,200);
		   w[i].setVisible(true);
		   w[i].setBackground(c[i]);
	   }
        for(int i=0;i<=4;i++)
        {
			w[i].setLocation(i*200,0);
		}
		for(int i=0;i<=4;i++)
		{
			w[i+5].setLocation(i*200,200);
		}

	}

}