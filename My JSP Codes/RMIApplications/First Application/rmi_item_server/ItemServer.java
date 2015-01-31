import java.rmi.*;
import java.rmi.server.*;

class ItemServer  {
	ItemServer() {
	}
	public static void main(String args[]) {
		try {
			ItemImplementor obj = new ItemImplementor();
			while(true) {
				Naming.rebind("item",obj);
			}
		}
		catch(Exception ex) {
			System.out.println("Error :"+ex);
		}
	}
}