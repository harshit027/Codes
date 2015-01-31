//not working

import java.awt.*;
import javax.swing.*;

class MyGraphics extends JFrame
{
	DrawingPanel dp;
	MyGraphics()
	{
		setSize(600,600);
		dp=new DrawingPanel();
		getContentPane().add(dp,"Center");
		setVisible(true);
	}

	public static void main(String args[])
	{
		new MyGraphics();
	}

}

class DrawingPanel extends JPanel
{
	public void paint(Graphics g)
	{
		Color c=new Color(0,0,0);
		g.setColor(c);
		g.drawLine(20,20,70,70);
		g.drawRect(70,10,120,60);
		g.setColor(new Color(200,200,200));
		g.fillRect(70,10,120,60);
		g.setColor(c);
		g.drawOval(200,10,100,100);

	}
}