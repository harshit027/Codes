import java.rmi.*;
import java.rmi.server.*;

class InterfaceImplementor extends UnicastRemoteObject implements InterfaceFile
{
	InterfaceImplementor ()throws RemoteException
	{
	}

	public String checkEven(int number)
	{
		String message="";
		try
		{
			if(number%2==0)
		   {
		    	message="Even Number";
		   }
		   else
		   message="Odd Number";
	   }
	   catch(Exception e)
	   {
		   System.out.println("Error : "+e);
	   }
		return message;
	}
}