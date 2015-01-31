import java.rmi.*;
import java.rmi.server.*;

class ItemImplementor extends UnicastRemoteObject implements Item {
	String [][]items = {
										{"1","Fan","1000", "Khaitan"},
										{"2","Tube Light","50", "Philips"},
										{"3","CFL","250","Orion"}
								};
	ItemImplementor() throws RemoteException {
	}
	public String getItemPrice(int itemId)  {
		String price="";
		try {
			for(int i=0;i<items.length;i++) {
				if(Integer.parseInt(items[i][0]) == itemId) {
					price = items[i][2];
					break;
				}
			}
		}
		catch(Exception ex) {
			System.out.println("Error :" +ex);
		}
		return price;
	}
	public String getItemDescription(int itemId) {
		String desc="";
		try {
			for(int i=0;i<items.length;i++) {
				if(Integer.parseInt(items[i][0]) == itemId) {
					desc = items[i][3];
					break;
				}
			}
		}
		catch(Exception ex) {
			System.out.println("Error :" +ex);
		}
		return desc;
	}
}