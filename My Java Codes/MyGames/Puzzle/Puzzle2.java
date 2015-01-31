//arrange the numbers in order using javax.swing

import java.awt.*;
import java.awt.event.*;
import java.util.Random;
import javax.swing.*;

class Puzzle2 extends JFrame implements ActionListener
{
	int counter=0;
	JButton btn[]=new JButton[9];
	JButton resetBtn;
	JButton scoreBtn;
	public static void main(String args[])

	{
		new Puzzle2();
	}

	Puzzle2()
	{
		setSize(400,400);
		setResizable(false);
		setTitle("PUZZLE-ARRANGE THE NUMBERS ROW-WISE");
		setLayout(new BorderLayout(20,20));

		//generator function
		Random rnd=new Random();
		int n[]=new int[]{0,1,2,3,4,5,6,7,8,9};
		int m[]=new int[10];
		int p=9,k=0;
		do
		{
		   int i=rnd.nextInt(p);
		   m[k]=n[i];
	       for(int j=i;j<p;j++)
		   {
	            n[j]=n[j+1];

		   }
           p--;
           k++;
	   }while(p>0);
	   //-------------------------------------------

        //north Panel
        JPanel northPanel=new JPanel();
        northPanel.setLayout(new FlowLayout(FlowLayout.CENTER));
        scoreBtn=new JButton("0");
        scoreBtn.setBackground(Color.red);
        scoreBtn.setForeground(Color.white);
        scoreBtn.setFont(new Font("Verdana",Font.BOLD,20));
        //scoreBtn.setEnabled(false);
        northPanel.add(scoreBtn);
        add(northPanel,"North");

		//center Panel
		JPanel centerPanel=new JPanel();
		centerPanel.setLayout(new GridLayout(3,3));
		for(int i=0;i<9;i++)
		{
			if(m[i]==0)
			{
				btn[i]=new JButton("");
				btn[i].setBackground(Color.pink);
				btn[i].setFont(new Font("Verdana",Font.BOLD,30));
				btn[i].addActionListener(this);
				centerPanel.add(btn[i]);
			}
			else
			{
				btn[i]=new JButton(""+m[i]);
			    btn[i].setFont(new Font("Verdana",Font.BOLD,30));
			    btn[i].setBackground(Color.yellow);

			    btn[i].addActionListener(this);
			    centerPanel.add(btn[i]);
			}
		}
		add(centerPanel,"Center");
        //-----------------------------------------------

		//bottom Panel
		JPanel bottomPanel=new JPanel();
		bottomPanel.setLayout(new FlowLayout(FlowLayout.CENTER));
		resetBtn=new JButton("RESET");
		resetBtn.setBackground(Color.blue);
		resetBtn.setForeground(Color.white);
		resetBtn.setFont(new Font("Verdana",Font.BOLD,20));
		resetBtn.addMouseListener(new MouseAdapter()
		                                                               {
																		   public void mouseClicked(MouseEvent me)
																		   {
																			   if(me.getSource()==resetBtn)
																			   {
																				   Random rnd=new Random();
																				   	int n[]=new int[]{0,1,2,3,4,5,6,7,8,9};
																				   	int m[]=new int[10];
																				   	int p=9,k=0;
																				   	do
																				   	{
																				   	   int i=rnd.nextInt(p);
																				   	   m[k]=n[i];
																				       for(int j=i;j<p;j++)
																				   	   {
																				            n[j]=n[j+1];
																				   	    }
																			           p--;
																			           k++;
	                                                                                 }while(p>0);
	                                                                                 for(int i=0;i<9;i++)
																					 {
																						if(m[i]==0)
																						{
																							btn[i].setLabel("");
																							btn[i].setBackground(Color.pink);
																						}
																						else
																						{
																							btn[i].setLabel(""+m[i]);
																							btn[i].setBackground(Color.yellow);
																						}
																					 }
																					 scoreBtn.setLabel("0");
																					 counter=0;
																				 }
																			 }
																		 });

	    bottomPanel.add(resetBtn);
	    add(bottomPanel,"South");

	    //closing window
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
		int i;
		for(i=0;i<9;i++)
		{
			if(ae.getSource()==btn[i])
			break;
		}

			if(i>2)
				{
					if(btn[i-3].getLabel().equals(""))
					{
						btn[i-3].setLabel(btn[i].getLabel());
				    	btn[i].setLabel("");
				    	btn[i].setBackground(Color.pink);
				    	btn[i-3].setBackground(Color.yellow);
					}
				}

				if(i<6)
				{
					if(btn[i+3].getLabel().equals(""))
					{
						btn[i+3].setLabel(btn[i].getLabel());
					    btn[i].setLabel("");
					    btn[i].setBackground(Color.pink);
					    btn[i+3].setBackground(Color.yellow);
					}
				}

				if(i!=0&&i!=3&&i!=6)
				{
					if(btn[i-1].getLabel().equals(""))
					{
						btn[i-1].setLabel(btn[i].getLabel());
						btn[i].setLabel("");
						btn[i].setBackground(Color.pink);
						btn[i-1].setBackground(Color.yellow);
					}
				}

			    if(i!=2&&i!=5&&i!=8)
				{
					if(btn[i+1].getLabel().equals(""))
					{
						btn[i+1].setLabel(btn[i].getLabel());
						btn[i].setLabel("");
						btn[i].setBackground(Color.pink);
						btn[i+1].setBackground(Color.yellow);
					}
				}
				int j;
				for(j=0;j<8;j++)
				{
					if(!btn[j].getLabel().equals((j+1)+""))
					break;
				}
				if(j==8)
		        {
					for(i=0;i<8;i++)
		            btn[i].setBackground(Color.green);
		            JOptionPane.showMessageDialog(this,"! ! ! ! ! ! BRAVO! ! ! ! ! !");
				}
                counter++;
                scoreBtn.setLabel(""+counter);
		}

}