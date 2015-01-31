import java.rmi.*;
import java.rmi.server.*;

class ServerFile
{
	public static void main(String args[])
	{
		try
		{
			InterfaceImplementor object=new InterfaceImplementor();
			while(true)
			{
				Naming .rebind("tableNum",object);
			}
		}
		catch(Exception ex)
		{
			System.out.println("Error : "+ex);
		}

	}
}
