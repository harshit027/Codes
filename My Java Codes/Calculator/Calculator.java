import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;

public class Calculator extends JApplet implements ActionListener
{
	JTextField num1TF,num2TF,resultTF;
	JButton plusB,minusB,multiplyB,divideB,modulusB;
	JLabel num1L,num2L,resultL;
	JPanel north,center,south;

	public Calculator()
	{
		setSize(400,400);
		setLayout(new BorderLayout(20,20));
		north=new JPanel();
		north.setLayout(new FlowLayout(FlowLayout.CENTER));
		JLabel header=new JLabel("CALCULATOR");
		header.setFont(new Font("verdana",1,20));
		north.add(header);
		getContentPane().add(north,"North");

		center =new JPanel();
		center.setLayout(new GridLayout(3,2));
	    num1L=new JLabel("1st Number");
	    num2L=new JLabel("2nd Number");
	    resultL=new JLabel("Result");
	    num1TF=new JTextField();
	    num2TF=new JTextField();
	    resultTF=new JTextField();
	    resultTF.setEditable(false);

	    center.add(num1L);
	    center.add(num1TF);
	    center.add(num2L);
	    center.add(num2TF);
	    center.add(resultL);
	    center.add(resultTF);

	    getContentPane().add(center,"Center");

	    south=new JPanel();
	    south.setLayout(new FlowLayout(FlowLayout.CENTER));
	    plusB=new JButton("+");
	    minusB=new JButton("-");
	    multiplyB=new JButton("*");
		divideB=new JButton("/");
		modulusB=new JButton("%");

		plusB.addActionListener(this);
		minusB.addActionListener(this);
		multiplyB.addActionListener(this);
		divideB.addActionListener(this);
		modulusB.addActionListener(this);

        plusB.setFont(new Font("verdana",1,15));
        minusB.setFont(new Font("verdana",1,15));
        multiplyB.setFont(new Font("verdana",1,15));
        divideB.setFont(new Font("verdana",1,15));
        modulusB.setFont(new Font("verdana",1,15));

		south.add(plusB);
		south.add(minusB);
		south.add(multiplyB);
		south.add(divideB);
		south.add(modulusB);
        getContentPane().add(south,"South");
		setVisible(true);
	}

	public void actionPerformed(ActionEvent ae)
	{
		float result=0;
		if(ae.getSource()==plusB)
		{

			result=Float.parseFloat(this.num1TF.getText())+Float.parseFloat(this.num2TF.getText());
			this.resultTF.setText(result+"");
		}
		else
		if(ae.getSource()==minusB)
		{

			result=Float.parseFloat(this.num1TF.getText())-Float.parseFloat(this.num2TF.getText());
			this.resultTF.setText(result+"");
		}
		else
		if(ae.getSource()==multiplyB)
		{


			result=Float.parseFloat(this.num1TF.getText())*Float.parseFloat(this.num2TF.getText());
			this.resultTF.setText(result+"");
		}
		else
		if(ae.getSource()==divideB)
		{

			result=Float.parseFloat(this.num1TF.getText())/Float.parseFloat(this.num2TF.getText());
			this.resultTF.setText(result+"");
		}
		else
		if(ae.getSource()==modulusB)
		{

			result=Float.parseFloat(this.num1TF.getText())%Float.parseFloat(this.num2TF.getText());
			this.resultTF.setText(result+"");
		}
	}

	/*public static void main(String args[])
	{
		new Calculator();
	}*/

	public void validateInput()
	{
		if(this.num1TF.getText()==null || this.num2TF.getText()==null)
		{
			JOptionPane.showMessageDialog(this,"Invalid Inputs");
			return;
		}
	}
}

