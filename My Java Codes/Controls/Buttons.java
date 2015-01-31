//creating  buttons

import java.awt.*;
import java.awt.event.*;

class Buttons extends Frame implements ActionListener
{
    Button bt[]=new Button[5];
	Buttons()
	{
		setSize(600,600);
		setVisible(true);
		setTitle("Button Example");

        setBackground(Color.pink);
        setResizable(false);
		addWindowListener(new WindowAdapter()
		                                                 {
															 public void windowClosing(WindowEvent we)
															 {
																 System.exit(0);
															 }
														 });


		setLayout(null);
		setForeground(Color.yellow);
		for(int i=0;i<5;i++)
		{
			bt[i]=new Button();
		    bt[i].addActionListener(this);
		    add(bt[i]);
		}

		for(int i=0;i<5;i++)
        bt[i].setBackground(Color.blue);

		bt[0].setBounds(50,50,100,70);
		bt[1].setBounds(450,50,100,70);
		bt[2].setBounds(50,450,100,70);
		bt[3].setBounds(450,450,100,70);
		bt[4].setBounds(250,250,100,70);

        bt[0].setLabel("A");
		bt[1].setLabel("B");
		bt[2].setLabel("C");
		bt[3].setLabel("D");
        bt[4].setLabel("E");
	}

	public void actionPerformed(ActionEvent ae)
	{
		Button ref=(Button)ae.getSource();
		if(ref==bt[0])
		{
		    setTitle("Button A Activated");
		    bt[0].setBackground(Color.red);
		    bt[1].setBackground(Color.blue);
		    bt[2].setBackground(Color.blue);
		    bt[3].setBackground(Color.blue);
		    bt[4].setBackground(Color.blue);
		}
		if(ref==bt[1])
		{
		    setTitle("Button B Activated");
		    bt[1].setBackground(Color.red);
		    bt[0].setBackground(Color.blue);
			bt[2].setBackground(Color.blue);
		    bt[3].setBackground(Color.blue);
		    bt[4].setBackground(Color.blue);
		}
		if(ref==bt[2])
		{
			setTitle("Button C Activated");
			bt[2].setBackground(Color.red);
			bt[0].setBackground(Color.blue);
		    bt[1].setBackground(Color.blue);
		    bt[3].setBackground(Color.blue);
		    bt[4].setBackground(Color.blue);
		}
		if(ref==bt[3])
		{
			setTitle("Button D Activated");
			bt[3].setBackground(Color.red);
			bt[0].setBackground(Color.blue);
		    bt[1].setBackground(Color.blue);
		    bt[2].setBackground(Color.blue);
		    bt[4].setBackground(Color.blue);
		}
		if(ref==bt[4])
		{
			setTitle("Button E Activated");
			bt[4].setBackground(Color.red);
		    bt[0].setBackground(Color.blue);
		    bt[1].setBackground(Color.blue);
		    bt[2].setBackground(Color.blue);
		    bt[3].setBackground(Color.blue);
		}

	}
	public static void main(String args[])
	{
		new Buttons();
	}
}
