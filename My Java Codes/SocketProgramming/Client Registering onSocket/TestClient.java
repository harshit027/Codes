import java.io.*;
import java.net.*;
import java.util.Scanner;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class TestClient extends JFrame implements ActionListener
{
	static JTextField fields[]=null;
	JLabel labels[]=null;
	static String captions[]={"Name","Degree","Branch","College"};
	JButton register,clear;
	JPanel center,south;
	static Socket s;
	static BufferedReader in;
	static PrintWriter out;

	public static void main(String args[])
	{
		try
		{
			s=new Socket("127.0.0.1",3200);
			in=new BufferedReader(new InputStreamReader(s.getInputStream()));
	        System.out.println(in.readLine());
		}
		catch(Exception e)
		{
			e.toString();
        }

		new TestClient();
		/*try
	    {

			Scanner obj=new Scanner(System.in);
	    	String names[]={"harshit","BE","IT","JEC"};
	        s=new Socket("127.0.0.1",3200);
	        String message="";
	        BufferedReader in=new BufferedReader(new InputStreamReader(s.getInputStream()));
	        PrintWriter out=new PrintWriter(s.getOutputStream(),true);
	        message=in.readLine();
	        System.out.println(message);
	        System.out.println("Enter data in string[]");
	        for(int i=0;i<4;i++)
	        {
				names[i]=obj.nextLine();
			}
	        int i=0;

	        while(i<4)
	        {
				out.println(names[i]);

	            i++;
			}
		}
		catch(Exception e)
		{
			e.toString();
		}
		try
		{
			s.close();
		}
		catch(Exception e)
		{
			e.toString();
		}
	}*/
}

	TestClient()
	{

		setSize(500,500);
		getContentPane().setLayout(new BorderLayout(20,20));
		labels=new JLabel[4];
	    fields=new JTextField[4];
	    for(int i=0;i<4;i++)
	    {
			labels[i]=new JLabel(captions[i]);
			fields[i]=new JTextField();
		}
		center=new JPanel();
		center.setLayout(new GridLayout(4,2,10,10));
        for(int i=0;i<4;i++)
        {
			center.add(labels[i]);
			center.add(fields[i]);
		}
		getContentPane().add(center,"Center");
	    south=new JPanel();
	    south.setLayout(new FlowLayout(FlowLayout.CENTER));
	    register=new JButton("Register");
	    register.addActionListener(this);
	    clear=new JButton("Clear");
	    clear.addActionListener(this);
		south.add(register);
		south.add(clear);
		getContentPane().add(south,"South");
		setVisible(true);
    }

    public void actionPerformed(ActionEvent ae)
    {
		if(ae.getSource()==register)
		{
          try
          {
			String names[]=new String[4];

		    String message="";
		    //in=new BufferedReader(new InputStreamReader(s.getInputStream()));
		    out=new PrintWriter(s.getOutputStream(),true);


	        for(int i=0;i<4;i++)
	        {
				names[i]=this.fields[i].getText();
			}
		        int i=0;

		        while(i<4)
		        {
					out.println(names[i]);
		            i++;
		    	}
			}
			catch(Exception e)
			{
				e.toString();
			}
			try
			{
				String message=in.readLine();
			    JOptionPane.showMessageDialog(this,message);
			}
			catch(Exception e)
			{
				e.toString();
			}
		}

		if(ae.getSource()==clear)
		{
			for(int i=0;i<4;i++)
			{
			    this.fields[i].setText("");
			}
		}
	}
}

