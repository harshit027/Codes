import java.awt.*;
import javax.swing.*;
import javax.swing.event.*;
import java.awt.event.*;

 class CardLayoutExample extends JFrame implements ActionListener
{
    CardLayout cards =new CardLayout();
    JButton one,two,three;
    JPanel cardsPanel;
    public static void main(String args[])
    {
        new CardLayoutExample();
    }
   CardLayoutExample()
   {
	    setSize(500,500);
	    getContentPane().setLayout(new BorderLayout(10,10));
	    cardsPanel=new JPanel();
    	cardsPanel.setLayout( cards);
	    cardsPanel.add( new JLabel("one",JLabel.CENTER), "one" );
	    cardsPanel.add( new JLabel("two",JLabel.CENTER), "two" );
        cardsPanel.add( new JLabel("three",JLabel.CENTER), "three" );
        getContentPane().add(cardsPanel,"Center");

        JPanel buttons=new JPanel();
        buttons.setLayout(new FlowLayout());
        one=new JButton("one");
        two=new JButton("two");
        three=new JButton("three");
        one .addActionListener(this);
        two.addActionListener(this);
        three.addActionListener(this);
        buttons.add(one);
        buttons.add(two);
        buttons.add(three);
        getContentPane().add(buttons,"North");
        setVisible(true);
	}

	public void actionPerformed(ActionEvent ae)
	{
		if(ae.getSource()==one)
		{
			cards.show(cardsPanel,"one");
		}
		if(ae.getSource()==two)
		{
			cards.show(cardsPanel,"two");
		}
		if(ae.getSource()==three)
		{
			cards.show(cardsPanel,"three");
		}
	}


}

