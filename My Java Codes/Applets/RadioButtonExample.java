import javax.swing.*;
import javax.swing.event.*;
import java.awt.*;
import java.awt.event.*;

public class RadioButtonExample extends JApplet implements ActionListener
{
	JRadioButton rb1,rb2,rb3,rb4;
	JButton btn;
	JTextField tf;
	JPanel north,south,center;
	ButtonGroup grp;
	public void init()
	{
		setSize(400,400);
		setLayout(new BorderLayout(10,10));

		north=new JPanel();
		north.setLayout(new GridLayout(4,1));
		rb1=new JRadioButton("Red");
		rb2=new JRadioButton("Yellow");
		rb3=new JRadioButton("Green");
		rb4=new JRadioButton("Blue");
		rb1.addActionListener(this);
		rb2.addActionListener(this);
		rb3.addActionListener(this);
		rb4.addActionListener(this);
		grp=new ButtonGroup();
		grp.add(rb1);
		grp.add(rb2);
		grp.add(rb3);
		grp.add(rb4);
		north.add(rb1);
		north.add(rb2);
		north.add(rb3);
		north.add(rb4);
		add(north,"North");

		center=new JPanel();
		btn=new JButton("Submit");
		btn.addActionListener(this);
		center.setLayout(new FlowLayout(FlowLayout.CENTER));
		center.add(btn);
		add(center,"Center");

		south=new  JPanel();
		tf=new JTextField(20);
		tf.setEditable(false);
		south.setLayout(new FlowLayout(FlowLayout.CENTER));
		south.add(tf);
		add(south,"South");
	}

	public void actionPerformed(ActionEvent ae)
	{

			if(ae.getSource()==btn)
			{
				if(rb1.isSelected()==true)
				   this.tf.setText(rb1.getText());
				else if(rb2.isSelected()==true)
				   this.tf.setText(rb2.getText());
				else if(rb3.isSelected()==true)
				   this.tf.setText(rb3.getText());
				else if(rb4.isSelected()==true)
				   this.tf.setText(rb4.getText());
				else
				   this.tf.setText("No option Selected");
			   }
	}
}

