import java.rmi.*;
import java.rmi.server.*;

class DbDataServer {
	public static void main(String args[]) {
		try {
			DbDataImpl db = new DbDataImpl();
			while(true) {
				Naming.rebind("dbobj", db);
			}
		}
		catch(Exception ex) {
			System.out.println("Error :"+ex);
		}
	}
}