import java.rmi.*;
import java.rmi.server.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;

class  ClientFile extends JFrame implements ActionListener
{
	JButton getDataBTN;
	JTextField numberTF;
	JLabel numberLBL;
	JPanel north,center;
	JTable table;
	JScrollPane jsp;
	ClientFile()
	{
		setSize(500,500);
		getDataBTN=new JButton("Get");
		getDataBTN.addActionListener(this);
		numberTF=new JTextField(20);
		numberLBL=new JLabel("Number");

		north=new JPanel();
		north.setLayout(new FlowLayout(FlowLayout.CENTER));
		north.add(numberLBL);
		north.add(numberTF);
        north.add(getDataBTN);
		getContentPane().add(north,"North");

		setVisible(true);
		try
		{
			System.setSecurityManager(new RMISecurityManager());
		}
		catch(Exception ex)
		{
			System.out.println("Error :"+ex);
		}
	}

	public void actionPerformed(ActionEvent ae)
	{
		//JOptionPane.showMessageDialog(this,"Working");
			try
			{
				String url = "rmi://localhost/";
			    InterfaceFile obj = (InterfaceFile) Naming.lookup(url+"tableNum");
			    int i= Integer.parseInt(this.numberTF.getText());
			    String message=obj.findTable(i);

			    String arr[]=message.split("$");
                String heads[]={"Table of Input"};
                String data[][]=new String[10][1];
			    for(int j=0;j<arr.length;j++)
			    {
				   data[j][1]=arr[j];
				}
                table=new JTable(data,heads);
                pnlTable.remove(jsp);
				pnlTable.add(jsp = new JScrollPane(tblData));
		    	pnlTable.revalidate();

			}
			catch(Exception ex)
			{
				System.out.println("Error : "+ex);
			}
	}

	public static void main(String args[])
	{
		new ClientFile();
	}
}

