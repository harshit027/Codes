import java.rmi.*;
import java.rmi.server.*;

interface InterfaceFile extends Remote
{
	public String checkEven(int number) throws RemoteException;
}
