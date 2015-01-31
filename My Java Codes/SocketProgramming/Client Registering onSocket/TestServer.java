import java.io.*;
import java.net.*;
import java.sql.*;

class TestServer
{
	static ServerSocket ss;
	static Socket s;
    static String entriesFromClient[]=new String[4];
    static BufferedReader in;
    static PrintWriter out;
	public static void main(String args[])
	{
		try
	    {
	    	String names[]=null;
	    	ss=new ServerSocket(3200);
	    	System.out.println("Server started");
	        s=ss.accept();

	        in=new BufferedReader(new InputStreamReader(s.getInputStream()));

	        out=new PrintWriter(s.getOutputStream(),true);
	        out.println("Client you are connected at "+s);

			int i=0;

            while(i<4)
            {
                entriesFromClient[i]=in.readLine();
			    i++;

			}

		}
		catch(Exception e)
		{
			e.toString();
		}
		for(int i=0;i<4;i++)
		System.out.println(entriesFromClient[i]);
		try
		{
			//s.close();
		    //ss.close();
		}
		catch(Exception e)
		{
			e.toString();
		}
		try
		{
			Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
		    Connection con=DriverManager.getConnection("jdbc:odbc:test_database");
		    PreparedStatement pst=con.prepareStatement("INSERT into student(sname,sdegree,sbranch,scollege) values(?,?,?,?)");
	        pst.setString(1,entriesFromClient[0]);
	        pst.setString(2,entriesFromClient[1]);
	        pst.setString(3,entriesFromClient[2]);
	        pst.setString(4,entriesFromClient[3]);

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

}

