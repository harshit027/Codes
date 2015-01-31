import javax.swing.*;
import java.awt.*;

public class MyApplet1 extends JApplet
{
	public void init()
	  {
		  getContentPane().setLayout(new BorderLayout(20,20));
		  getContentPane().setBackground(Color.orange);
		  JPanel MyPanel=new JPanel();
		  MyPanel.setLayout(new FlowLayout(FlowLayout.LEFT));
		  MyPanel.setLocation(100,100);
		  MyPanel.add(new JLabel("Name"));
		  MyPanel.add(new JTextField(15));
		  MyPanel.add(new JButton("Submit"));
		  MyPanel.setBackground(Color.lightGray);
		  getContentPane().add(MyPanel,"Center");
          getContentPane().add(new JLabel("My First Applet",JLabel.CENTER),"North");

  }
  //Embedded html code for appletviewer
  //type on cprompt 'appletviewer MyApplet1.java'
  //<applet code=MyApplet1 width=400 height=400 >
//</applet>
}