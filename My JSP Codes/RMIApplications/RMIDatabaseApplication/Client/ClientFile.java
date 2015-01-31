import java.rmi.*;
import java.rmi.server.*;

class ClientFile {
	public static void main(String args[]) {
		try {
			int i=Integer.parseInt(args[0]);
			System.setSecurityManager(new RMISecurityManager());
			String url = "rmi://localhost/";
			InterfaceFile obj = (InterfaceFile) Naming.lookup(url+"number");
			System.out.println(obj.checkEven(i));

		}
		catch(Exception ex) {
			System.out.println("Error :"+ex);
		}
	}
}