import java.rmi.*;
import java.rmi.server.*;

class InterfaceImplementor extends UnicastRemoteObject implements InterfaceFile
{
	InterfaceImplementor() throws RemoteException
	{
	}
	public String  findTable(int num) throws RemoteException
	{
		String  message="";
		for(int i=0;i<10;i++)
		message=num+" * "+i+" = "+(num*i)+"$";
		return message;

	}
}