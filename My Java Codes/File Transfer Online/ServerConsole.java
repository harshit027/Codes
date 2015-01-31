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
	JButton browse,send;
	JTextField filenameField;
	JFileChooser jfc;
	String filedata="";

	ServerConsole()
	{
		setSize(400,150);
		getContentPane().setLayout(new BorderLayout(10,10));

		north=new JPanel();
		north.setLayout(new FlowLayout(FlowLayout.LEFT));
		browse=new JButton("Browse");
		send=new JButton("Send");
		browse.addActionListener(this);
		send.addActionListener(this);
		north.add(browse);
		north.add(send);
		getContentPane().add(north,"North");

		center=new JPanel();
		center.setLayout(new FlowLayout(FlowLayout.LEFT));
		filenameField=new JTextField(100);
		center.add(filenameField);
		getContentPane().add(center,"Center");

	    south=new JPanel();
		startServer=new JButton("Start Server");
		south.setLayout(new FlowLayout(FlowLayout.CENTER));
		startServer.addActionListener(this);
		south.add(startServer);
		getContentPane().add(south,"South");

		jfc=new JFileChooser();
        setVisible(true);
	}

	public void actionPerformed(ActionEvent ae)
	{
		if(ae.getSource()==startServer)
		{
			server=new ServerThread(this);
		}
		if(ae.getSource()==browse)
		{
			jfc.showOpenDialog(this);
			File file=jfc.getSelectedFile();
			this.filenameField.setText(file.getName());
			try
			{
				BufferedReader in=new BufferedReader(new FileReader(file.getPath()));
				while(true)
				{
					String line=in.readLine();
					if(line==null)
					break;
					filedata=filedata+line+"\n";
				}
			}
			catch(Exception e)
			{
				System.out.println("Error : "+e);
			}
		}
		if(ae.getSource()==send)
		{
			if(server==null)
			{
				JOptionPane.showMessageDialog(this,"No Connection : Start Server !");
				return;
			}
			if(this.filedata==null)
			{
				JOptionPane.showMessageDialog(this,"No file selected !");
				return;
			}
			try
			{
				PrintWriter out=new PrintWriter(server.s.getOutputStream(),true);
				out.println("FILENAME:"+filenameField.getText());
				out.println(this.filedata);
				out.println("ENDFILE");
				System.out.print(filedata);
			}
			catch(Exception e)
			{
				System.out.println("Error : "+e);
			}
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
				out.println(s);
			}
			catch(Exception e)
			{
				System.out.println("Error :"+e);
			}
		}
	}



