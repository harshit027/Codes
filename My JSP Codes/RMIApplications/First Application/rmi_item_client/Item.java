import java.rmi.*;
import java.rmi.server.*;

interface Item extends Remote {
	public String getItemPrice(int itemId) throws RemoteException;
	public String getItemDescription(int itemId) throws RemoteException;
}