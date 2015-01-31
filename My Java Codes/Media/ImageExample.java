import javax.swing.*;
import java.awt.*;

class ImageExample extends JFrame
{
	ImageExample()
	{
		setSize(500,500);
		ImageIcon img=new ImageIcon("MSN.jpg");
		getContentPane().setLayout(new BorderLayout(20,20));
		JLabel jlbl=new JLabel(img,JLabel.CENTER);
		getContentPane().add(jlbl,"Center");
		setVisible(true);
	}
	public static void main(String args[])
	{
		new ImageExample();
	}
}

