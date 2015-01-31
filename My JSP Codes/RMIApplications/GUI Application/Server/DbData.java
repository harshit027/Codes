import java.rmi.*;
import java.rmi.server.*;

interface DbData extends Remote {
	String getEmpData(int deptno) throws RemoteException;
}