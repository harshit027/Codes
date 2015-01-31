import javax.swing.*;
import java.awt.event.*;
import javax.swing.event.*;
import java.awt.*;
import java.io.*;
import java.net.*;
import java.sql.*;


class TestServer extends JFrame implements ActionListener
{
	JButton startB;
	TestServer()
	{
		setSize(400,400);
		setLayout(new FlowLayout());
		startB=new JButton("Start");
		startB.addActionListener(this);
		add(startB);
		setVisible(true);
	}

	public void actionPerformed(ActionEvent ae)

	{
		if(ae.getSource()==startB)
	    {
	    	new ServerThread(this);
	    }
	}





		/*try
		{
		   ss=new ServerSocket(3200);
		   System.out.println("Server Started");
		   s=ss.accept();

		   in=new BufferedReader(new InputStreamReader(s.getInputStream()));
		   out=new PrintWriter(s.getOutputStream(),true);
		   out.println("Connected : "+s);
		   flag=in.readLine();
		   System.out.println(flag);
	   }
	   catch(Exception e)
	   {
		   e.toString();
	   }

	   String entriesFromClient[]=new String [2];
	   try
	   {
	        for(int i =0;i<2;i++)
	        {
		        entriesFromClient[i]=in.readLine();
		        System.out.println(entriesFromClient[i]);
	        }
		}
		catch(Exception e)
		{
			e.toString();
		}
       if(flag.equals("register"))
       {
	       try
	       {
		     Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
		     Connection con=DriverManager.getConnection("jdbc:odbc:test1_database");
		     PreparedStatement pst=con.prepareStatement("INSERT into student(Names,Rollno) values(?,?)");
		     pst.setString(1,entriesFromClient[0]);
		     pst.setString(2,entriesFromClient[1]);
		     int count=pst.executeUpdate();
		     if(count>0)
		     {
		     	    out.println("You Are Registered Successfully !");
		    		System.out.println("Student Saved");

		     }
		     else
		     {
		     	out.println("Error Occured !");
		        System.out.println("Error in saving");
		     }
		     con.close();
		  }
		   catch(Exception e)
		   {
		    	e.toString();
		   }
	   }

	   if(flag.equals("login"))
	   {
		   try
		   {
			   int check=0;
			   Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
			   Connection con=DriverManager.getConnection("jdbc:odbc:test1_database");
			   Statement st=con.createStatement();
			   ResultSet rs=st.executeQuery("SELECT * from student");
			   while(rs.next())
			   {
				   if(rs.getString(2).equalsIgnoreCase(entriesFromClient[0])&&rs.getString(3).equalsIgnoreCase(entriesFromClient[1]))
				   {
					   check=1;
				   }
			   }
			   if(check==1)
			   {
				   out.println("You are verified !");
				   System.out.println("Verified !");
			   }
			   else
			   {
				   out.println("You are not verified !");
				   System.out.println("Not verified !");
		       }
			   rs.close();
			   con.close();
		   }
		   catch(Exception e)
		   {
			   e.toString ();
		   }

	   }*/


   public static void main(String args[])
   {
	   new TestServer();

   }
}

class ServerThread extends Thread
{
	Socket s;
	TestServer ref;
	ServerSocket ss;
	ServerThread(TestServer ref)
	{
		this.ref=ref;
		start();
	}

	public void run()
	{
		try
		{
			ss=new ServerSocket(4000);
			System.out.println("Server started : "+ss);
		    while(true)
		    {
		    	s=ss.accept();

		    	new ActiveThreadOnServer(ref,s);
		    }
		}
		catch(Exception e)
		{
			System.out.print("Exception in ServerThread : "+e);
		}
	}
}

class ActiveThreadOnServer extends Thread
{
	Socket s;
	TestServer ref;
	BufferedReader in;
	PrintWriter out;
	String data[]=null;

	ActiveThreadOnServer(TestServer ref,Socket s)
	{
		this.s=s;
		this.ref=ref;
		start();
	}

	public void run()
	{
		data=new String [2];
		try
		{
			in=new BufferedReader(new InputStreamReader(s.getInputStream()));
			out=new PrintWriter(s.getOutputStream(),true);
			out.println("Host Address : "+s);
			System.out.println(in.readLine());
			while(true)
			{
				String flag;
				flag=in.readLine();
				for(int i=0;i<2;i++)
				{
					data[i]=in.readLine();
					System.out.println(data[i]);
				}
				if(flag.equals("register"))
				{
					try
				     {
					     Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
					     Connection con=DriverManager.getConnection("jdbc:odbc:test1_database");
					     PreparedStatement pst=con.prepareStatement("INSERT into student(Names,Rollno) values(?,?)");
					     pst.setString(1,data[0]);
					     pst.setString(2,data[1]);
					     int count=pst.executeUpdate();
					     if(count>0)
					     {
					     	    out.println("You Are Registered Successfully !");
					    		System.out.println("Student Saved");

					     }
					     else
					     {
					     	out.println("Error Occured !");
					        System.out.println("Error in saving");
					     }
					     con.close();
					  }
					   catch(Exception e)
					   {
					    	e.toString();
		               }
				}
				else if(flag.equals("login"))
				{
					try
				   {
					   int check=0;
					   Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
					   Connection con=DriverManager.getConnection("jdbc:odbc:test1_database");
					   Statement st=con.createStatement();
					   ResultSet rs=st.executeQuery("SELECT * from student");
					   while(rs.next())
					   {
						   if(rs.getString(2).equalsIgnoreCase(data[0])&&rs.getString(3).equalsIgnoreCase(data[1]))
						   {
							   check=1;
						   }
					   }
					   if(check==1)
					   {
						   out.println("You are verified !");
						   System.out.println("Verified !");
					   }
					   else
					   {
						   out.println("You are not verified !");
						   System.out.println("Not verified !");
				       }
					   rs.close();
					   con.close();
				   }
				   catch(Exception e)
				   {
					   e.toString ();
		           }
				}
			}
		}
		catch(Exception e)
		{
			System.out.println("Exception in ActiveThread : "+e);
		}

	}
}









