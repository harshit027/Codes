//changes the title on pressing keys1

import java.awt.event.*;
import java.awt.*;
class MyEvent4 extends Frame implements KeyListener
{
	public static void main(String args[])
	{
		MyEvent4 e1=new MyEvent4();

	}
	int n=0;
	MyEvent4()
	{
		setSize(200,200);
        setTitle("Press q to exit");
		setVisible(true);
		addKeyListener(this);
	}
public void keyPressed(KeyEvent ke)
{
	if(ke.getKeyChar()=='q')
	System.exit(0);
}
public void keyReleased(KeyEvent ke)
{
}
public void keyTyped(KeyEvent ke)
{
	String s="MyWindow";
	for(int i=0;i<4;i++)
	{
	   s="MyWindow"+ke.getKeyChar();

	   setTitle(s);
    }


}

}