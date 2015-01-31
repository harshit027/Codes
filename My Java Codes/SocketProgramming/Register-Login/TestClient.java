import javax.swing.*;
import java.awt.event.*;
import javax.swing.event.*;
import java.awt.*;
import java.io.*;
import java.net.*;
import java.sql.*;
import java.util.Date;

class RegisterPanel extends JPanel implements ActionListener
{
	JPanel rcenter,rsouth;
	JButton register;
	JTextField tf_name,tf_rollno;
	JLabel lb_name,lb_rollno;
	String entries[]=null;

	RegisterPanel()
	{
		setLayout(new BorderLayout(20,20));
		rcenter=new JPanel();
		rcenter.setLayout(new GridLayout(2,2,20,180));
		tf_name=new JTextField(40);
		tf_rollno=new JTextField(40);
		lb_name=new JLabel("Name");
		lb_name.setFont(new Font("Verdana,",Font.BOLD,16));
		lb_rollno=new JLabel("Roll No");
		lb_rollno.setFont(new Font("Verdana,",Font.BOLD,16));
		rcenter.add(lb_name);
		rcenter.add(tf_name);
		rcenter.add(lb_rollno);
		rcenter.add(tf_rollno);
		add(rcenter,"Center");

		rsouth=new JPanel();
		rsouth.setLayout(new FlowLayout(FlowLayout.CENTER));
		register=new JButton("Register");
		register.addActionListener(this);
		rsouth.add(register);
		add(rsouth,"South");

		entries=new String[2];

	}
	public void actionPerformed(ActionEvent ae)
	{

        if(ae.getSource()==register)
        {
			try
			{
				System.out.println("register");
			    entries[0]=tf_name.getText();
		        entries[1]=tf_rollno.getText();
                //System.out.println(this.entries[0]);
                //System.out.println(this.entries[1]);
                ActiveThreadOnClient.out.println("register");
	            ActiveThreadOnClient.out.println(entries[0]);
                ActiveThreadOnClient.out.println(entries[1]);
                JOptionPane.showMessageDialog(this,ActiveThreadOnClient.in.readLine());
			}
			catch(Exception e)
			{
				System.out.println("Error in Register Button : "+e);
			}
		}

	}
}

class LoginPanel extends JPanel implements ActionListener
{
	JPanel lcenter,lsouth;
	JButton login;
	JTextField tf_username,tf_password;
	JLabel lb_username,lb_password;
    String entries[]=null;
	LoginPanel()
	{
		setLayout(new BorderLayout(20,20));
		lcenter=new JPanel();
		lcenter.setLayout(new GridLayout(2,2,20,180));
		tf_username=new JTextField(40);
		tf_password=new JTextField(40);
		lb_username=new JLabel("Username");
		lb_password=new JLabel("Password");
		lb_username.setFont(new Font("Verdana,",Font.BOLD,16));
		lb_password.setFont(new Font("Verdana,",Font.BOLD,16));
		lcenter.add(lb_username);
		lcenter.add(tf_username);
		lcenter.add(lb_password);
		lcenter.add(tf_password);
		add(lcenter,"Center");

		lsouth=new JPanel();
		lsouth.setLayout(new FlowLayout(FlowLayout.CENTER));
		login=new JButton("Login");
		login.addActionListener(this);
		lsouth.add(login);
		add(lsouth,"South");
		entries=new String[2];
	}
	public void actionPerformed(ActionEvent ae)
	{
		if(ae.getSource()==login)
		{
			try
			{
				System.out.println("login");
			    entries[0]=tf_username.getText();
		        entries[1]=tf_password.getText();
		        //System.out.println(this.entries[0]);
		        //System.out.println(this.entries[1]);
		        ActiveThreadOnClient.out.println("login");
		        ActiveThreadOnClient.out.println(entries[0]);
	            ActiveThreadOnClient.out.println(entries[1]);
	           JOptionPane.showMessageDialog(this,ActiveThreadOnClient.in.readLine());
			}
			catch(Exception e)
			{
				System.out.println("Error in Register Button : "+e);
			}
		}

	}
}

class TestClient extends JFrame implements ActionListener
{
	JButton addnew,verify;
	static RegisterPanel reg_panel;
	static LoginPanel log_panel;
	static JPanel main_center,main_south;
	CardLayout cards=new CardLayout();




	TestClient()
	{
		/*try
		{
			s=new Socket("localhost",3200);
			in=new BufferedReader(new InputStreamReader(s.getInputStream()));
			out=new PrintWriter(s.getOutputStream(),true);
			System.out.println(in.readLine());
		}
		catch(Exception e)
		{
			e.toString();
		}*/
		setSize(400,400);
		getContentPane().setLayout(new BorderLayout(20,20));
		reg_panel=new RegisterPanel();
		log_panel=new LoginPanel();
		main_center=new JPanel();
		main_center.setLayout(cards);
		main_center.add(reg_panel,"Register");
		main_center.add(log_panel,"Login");
		getContentPane().add(main_center,"Center");

	    main_south=new JPanel();
		main_south.setLayout(new FlowLayout(FlowLayout.CENTER));
    	addnew=new JButton("New");
		verify=new JButton("Verify");
		addnew.addActionListener(this);
		verify.addActionListener(this);
		main_south.add(addnew);
		main_south.add(verify);
		getContentPane().add(main_south,"South");
		setVisible(true);
		new ClientThread(this);
	}

	public void actionPerformed(ActionEvent ae)
	{
		if(ae.getSource()==addnew)
		{
			cards.show(main_center,"Register");
		}
		if(ae.getSource()==verify)
		{
			cards.show(main_center,"Login");
		}
	}
	public static void main(String args[])
	{
		new TestClient();
	}
}

class ClientThread extends Thread
{
	TestClient ref;
	Socket s=null;
	ClientThread(TestClient ref)
	{
		this.ref=ref;
		start();
	}

	public void run()
	{
		try
		{
			s=new Socket("127.0.0.1",4000);
		    new ActiveThreadOnClient(s,ref);
		}
		catch(Exception e)
		{
			System.out.println("Error in ClientThread: "+e);
		}
	}
}

class ActiveThreadOnClient extends Thread
{
	TestClient ref;
	Socket s;
	Date dt;
    static BufferedReader in;
    static PrintWriter out;
	ActiveThreadOnClient(Socket s,TestClient ref)
	{
		this.s=s;
		this.ref=ref;
		start();
	}

	public void run()
	{
		dt=new Date();
		try
		{
			 in=new BufferedReader(new InputStreamReader(s.getInputStream()));
		    out=new PrintWriter(s.getOutputStream(),true);
		    JOptionPane.showMessageDialog(ref,in.readLine());
		    out.println("Client : "+dt.getHours()+":"+dt.getMinutes()+":"+dt.getSeconds());
		}
		catch(Exception e)
		{
			System.out.println("Error in ActiveThreadOnClient: "+e);
		}
	}
}


