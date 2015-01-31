import java.rmi.*;
import java.rmi.server.*;

class ItemClient {
	public static void main(String args[]) {
		try {
			System.setSecurityManager(new RMISecurityManager());
			String url = "rmi://localhost/";
			Item obj = (Item) Naming.lookup(url+"item");
			System.out.println(obj.getItemPrice(1));
			System.out.println(obj.getItemDescription(1));
			System.out.println(obj.getItemPrice(2));
			System.out.println(obj.getItemDescription(2));
		}
		catch(Exception ex) {
			System.out.println("Error :"+ex);
		}
	}
}