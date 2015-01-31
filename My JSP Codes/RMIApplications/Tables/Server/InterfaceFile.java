import java.rmi.*;
import java.rmi.server.*;

interface InterfaceFile extends Remote
{
	public String findTable(int num) throws RemoteException;
}