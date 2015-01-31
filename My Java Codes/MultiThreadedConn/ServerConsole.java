import java.io.*;
import java.awt.*;
import javax.swing.*;
import javax.swing.event.*;
import java.net.*;
import java.awt.event.*;

class ServerConsole extends JFrame implements ActionListener
{
	JButton startServer;
	JPanel north,center,south;
	ServerThread server;

	ServerConsole()
	{
		setSize(200,200);
		getContentPane().setLayout(new BorderLayout(10,10));

		south=new JPanel();
		startServer=new JButton("Start Server");
		south.setLayout(new FlowLayout(FlowLayout.CENTER));
		startServer.addActionListener(this);
		south.add(startServer);

		getContentPane().add(south,"South");
        setVisible(true);
	}

	public void actionPerformed(ActionEvent ae)
	{
		if(ae.getSource()==startServer)
		{
			server=new ServerThread(this);
		}
	}

	public static void main(String args[])
	{
		new ServerConsole();
	}
}

class ServerThread extends Thread
{
	ServerConsole ref;
	Socket s=null;
	ServerThread(ServerConsole ref)
	{
		this.ref=ref;
		start();
	}
	public void run()
	{
		try
		{
			ServerSocket ss=new ServerSocket(4000);
			JOptionPane.showMessageDialog(ref,"ServerStarted");
			System.out.println("Server Started : "+ss);
			while(true)
			{
				s=ss.accept();
				new ClientThreadOnServer(s,ref);
			}
		}
		catch(Exception e)
		{
			System.out.println("Error :"+e);
		}
	}
}

	class ClientThreadOnServer extends Thread
	{
		ServerConsole ref;
		Socket s;
		BufferedReader in;
		PrintWriter out;
		ClientThreadOnServer(Socket s,ServerConsole ref)
		{
			this.s=s;
			this.ref=ref;
			start();
		}
		public void run()
		{
			try
			{
				in=new BufferedReader(new InputStreamReader(s.getInputStream()));
				out=new PrintWriter(s.getOutputStream(),true);
				out.println("Connection : "+s);
			}
			catch(Exception e)
			{
				System.out.println("Error :"+e);
			}
		}
	}



