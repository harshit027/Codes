import java.rmi.*;
import java.rmi.server.*;

class ServerFile
{
	ServerFile()
	{
		System.out.println("Server Started : Waiting for Clients.....");
	}
	public static void main(String args[])
	{
		new ServerFile();
		try
		{
			InterfaceImplementor obj=new InterfaceImplementor();
		    while(true)
		   {
		    	Naming.rebind("number",obj);
		   }
	   }
	   catch(Exception e)
	   {
		   System.out.println("Error : "+e);
	   }
	}

}
