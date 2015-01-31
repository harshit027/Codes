import java.io.*;
import java.awt.*;
import javax.swing.*;
import javax.swing.event.*;
import java.net.*;
import java.awt.event.*;

class ClientConsole extends JFrame implements ActionListener
{
	JButton connectToServer;
	JPanel center,south,north;
	ClientThread client;
	{
		setSize(400,400);
		getContentPane().setLayout(new BorderLayout(10,10));
		south=new JPanel();
		connectToServer=new JButton("Connect");
		connectToServer.addActionListener(this);
		south.setLayout(new FlowLayout(FlowLayout.CENTER));
		south.add(connectToServer);

		getContentPane().add(south,"South");
		setVisible(true);
	}

	public void actionPerformed(ActionEvent ae)
	{
		if(ae.getSource()==connectToServer)
		{
			client=new ClientThread(this);
		}
	}

	public static void main(String args[])
	{
		new ClientConsole();
	}
}

class ClientThread extends Thread
{
	ClientConsole ref;
	Socket s;
	ClientThread(ClientConsole ref)
	{
		this.ref=ref;
		start();
	}

	public void run()
	{
		try
		{
			s=new Socket("127.0.0.1",4000);
		    new ClientThreadOnClient(s,ref);
		}
		catch(Exception e)
		{
			System.out.println("Error : "+e);
		}
	}
}

class ClientThreadOnClient extends Thread
{
	ClientConsole ref;
	Socket s;
	ClientThreadOnClient(Socket s,ClientConsole ref)
	{
		this.s=s;
		this.ref=ref;
		start();
	}

	public void run()
	{
		try
		{
			BufferedReader in=new BufferedReader(new InputStreamReader(s.getInputStream()));
		    PrintWriter pw=new PrintWriter(s.getOutputStream(),true);
		    System.out.println(in.readLine());
		}
		catch(Exception e)
		{
			System.out.println("Error : "+e);
		}
	}
}



