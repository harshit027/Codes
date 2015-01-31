import java.awt.*;
import javax.swing.*;
import java.io.*;
import java.net.*;
import java.awt.event.*;

public class ShowHTML extends JApplet implements ActionListener
{
	  JButton send = new JButton("Go......");
	  JLabel l = new JLabel();
	  public void init()
	  {
	      setLayout(new FlowLayout());
	      send.addActionListener(this);
	      add(send);
          add(l);
	  }
	  public void actionPerformed(ActionEvent ae)
	  {
		  if(ae.getSource()==send)
		  {
			  try
	          {
		  	          URL u = new URL(getDocumentBase(),"form1.html");
		  	          getAppletContext().showDocument(u);
		  	   }

		  	   catch(Exception e)
	           {
		  	          l.setText(e.toString());
	           }
		   }
		}
}

