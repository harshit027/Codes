//Tic Tac Toe game

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;
class TicTacToe extends JFrame implements ActionListener
{
	 JButton bt[]=new JButton[9];
	 JButton btnReset;
	 int counter=0;
	public static void main(String args[])
	{
		new TicTacToe();
	}

	TicTacToe()
	{
		setLayout(new BorderLayout(20,20));
		setSize(400,450);
        setTitle("TIC-TAC-TOE");
        //setForeground(Color.red);
        setResizable(false);

        //Header
        JPanel northPanel=new JPanel();
        northPanel.setLayout(new FlowLayout(FlowLayout.CENTER));
        JLabel lblHeader=new JLabel("TIC----TAC----TOE");
        northPanel.setForeground(Color.red);
        lblHeader.setFont(new Font("TimesRoman",Font.BOLD,30));
        northPanel.add(lblHeader);
        add(northPanel,"North");

		//Center panel
		JPanel cntrPanel=new JPanel();
   		cntrPanel.setLayout(new GridLayout(3,3));
        add(cntrPanel,"Center");
	    for(int i=0;i<9;i++)
	    {
			bt[i]=new JButton();

            bt[i].setBackground(Color.yellow);
            bt[i].setForeground(Color.black);
            bt[i].setFont(new Font("Verdana",Font.BOLD,60));
            cntrPanel.add(bt[i]);
            bt[i].addActionListener(this);

			/*bt[i].addMouseListener(new MouseAdapter() //you can also use mouseListener
			                                                      {
																	  public void mouseClicked(MouseEvent me)
																	  {
																		 for(int i=0;i<9;i++)
																		 {
																			 if(me.getSource()==bt[i])
																			 {
																				 switch(counter)
																				 {
																					 case 0:
																					 {
																						 bt[i].setLabel("X");
																						 //bt[i].setEnabled(false);
																						 checkWinner();

																						 break;
																					 }
																					 case 1:
																					 {
																						 bt[i].setLabel("O");
																						 //bt[i].setEnabled(false);
																						 checkWinner();

																					 }
																				 }
																				 counter++;
																				 if(counter>1) counter=0;
																			 }
																		 }
																	 }
																 });
				bt[i].addKeyListener(new KeyAdapter()   //you can also use keyListener
			                                                    {
																	public void keyTyped(KeyEvent ke)
														            {
																		int n=0;
																		JButton bref=(JButton) ke.getSource();
																		for(int i=0;i<9;i++)
																		{
																			if(bref==bt[i])
																			{
																				if(ke.getKeyChar()=='X' || ke.getKeyChar()=='x')
																				{
																					bt[i].setLabel("X");
                                                                                    //bt[i].setEnabled(false);
																					checkWinner();

																				}
																				if(ke.getKeyChar()=='O' || ke.getKeyChar()=='o')
																				{
																					bt[i].setLabel("O");
                                                                                    //bt[i].setEnabled(false);
																					checkWinner();

																				}
																			}
																		}
																	}
																  });*/


		}

		//Bottom Panel
        JPanel btmPanel=new JPanel();
        btmPanel.setLayout(new FlowLayout(FlowLayout.CENTER));
        add(btmPanel,"South");
        btnReset =new JButton("RESET");
        btnReset.setFont(new Font("Verdana",Font.BOLD,16));
        btnReset.setBackground(Color.green);
        btnReset.setForeground(Color.black);
        btnReset.addMouseListener(new MouseAdapter()
                                                                        {
																			public void mouseClicked(MouseEvent me)
																			{
																				if(me.getSource()==btnReset)
																				{
																					for(int i=0;i<9;i++)
																					{
																						bt[i].setLabel("");
     																					bt[i].setEnabled(true);
																						bt[i].setBackground(Color.yellow);
																					}
																				}
																			}
																		});
        btmPanel.add(btnReset);


		//Window Closing
		addWindowListener(new WindowAdapter()
		                                                 {
															public void windowClosing(WindowEvent we)
															{
																System.exit(0);
															}
														});
	    setVisible(true);

	}

   public void actionPerformed(ActionEvent ae)
   {
	   for(int i=0;i<9;i++)
	   {
		   if(ae.getSource()==bt[i])

			   {
				 switch(counter)
			   	{
			    	 case 0:
			   		 {
			   			 bt[i].setLabel("X");
			   			 bt[i].setEnabled(false);
			   			 checkWinner();

			   			 break;
			   		 }
			   		 case 1:
			   		 {
			   			 bt[i].setLabel("O");
			   			 bt[i].setEnabled(false);
			    		 checkWinner();

			   		 }
			   	}
			   counter++;
			   if(counter>1) counter=0;
			 }
		 }
	 }

    public void checkWinner()
	{
		if((bt[0].getLabel()=="X"&&bt[1].getLabel()=="X" && bt[2].getLabel()=="X")||(bt[0].getLabel()=="O"&&bt[1].getLabel()=="O" && bt[2].getLabel()=="O"))
		{
			bt[0].setBackground(Color.red);
			bt[1].setBackground(Color.red);
			bt[2].setBackground(Color.red);
		}
		if((bt[3].getLabel()=="X"&&bt[4].getLabel()=="X" && bt[5].getLabel()=="X")||(bt[3].getLabel()=="O"&&bt[4].getLabel()=="O" && bt[5].getLabel()=="O"))
				{
					bt[3].setBackground(Color.red);
					bt[4].setBackground(Color.red);
					bt[5].setBackground(Color.red);
		}
		if((bt[6].getLabel()=="X"&&bt[7].getLabel()=="X" && bt[8].getLabel()=="X")||(bt[6].getLabel()=="O"&&bt[7].getLabel()=="O" && bt[8].getLabel()=="O"))
				{
					bt[6].setBackground(Color.red);
					bt[7].setBackground(Color.red);
					bt[8].setBackground(Color.red);
		}
		if((bt[0].getLabel()=="X"&&bt[3].getLabel()=="X" && bt[6].getLabel()=="X")||(bt[0].getLabel()=="O"&&bt[3].getLabel()=="O" && bt[6].getLabel()=="O"))
				{
					bt[0].setBackground(Color.red);
					bt[3].setBackground(Color.red);
					bt[6].setBackground(Color.red);
		}
		if((bt[1].getLabel()=="X"&&bt[4].getLabel()=="X" && bt[7].getLabel()=="X")||(bt[1].getLabel()=="O"&&bt[4].getLabel()=="O" && bt[7].getLabel()=="O"))
				{
					bt[1].setBackground(Color.red);
					bt[4].setBackground(Color.red);
					bt[7].setBackground(Color.red);
		}
		if((bt[2].getLabel()=="X"&&bt[5].getLabel()=="X" && bt[8].getLabel()=="X")||(bt[2].getLabel()=="O"&&bt[5].getLabel()=="O" && bt[8].getLabel()=="O"))
				{
					bt[2].setBackground(Color.red);
					bt[5].setBackground(Color.red);
					bt[8].setBackground(Color.red);
		}
		 if((bt[0].getLabel()=="X"&&bt[4].getLabel()=="X" && bt[8].getLabel()=="X")||(bt[0].getLabel()=="O"&&bt[4].getLabel()=="O" && bt[8].getLabel()=="O"))
				{
					bt[0].setBackground(Color.red);
					bt[4].setBackground(Color.red);
					bt[8].setBackground(Color.red);
		}
		if((bt[2].getLabel()=="X"&&bt[4].getLabel()=="X" && bt[6].getLabel()=="X")||(bt[2].getLabel()=="O"&&bt[4].getLabel()=="O" && bt[6].getLabel()=="O"))				{
					bt[2].setBackground(Color.red);
					bt[4].setBackground(Color.red);
					bt[6].setBackground(Color.red);
		}
	}
}



