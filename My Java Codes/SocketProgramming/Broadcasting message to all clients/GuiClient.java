import java.net.*;
import java.io.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;

class GuiClient extends JFrame implements ActionListener{
	JTextArea taMessage = new JTextArea(10,40);
	JTextArea taSendMessage = new JTextArea(4,40);
	JButton btnSend = new JButton("Send");
	JPanel pnlBottom = new JPanel();
	ConnecToServer clientSocket;
	public static void main(String args[]) {
		new GuiClient();
	}
	public void actionPerformed(ActionEvent ae) {
		try {
			PrintWriter pw = new PrintWriter(clientSocket.s.getOutputStream(),true);
			pw.println(taSendMessage.getText());
			//taMessage.setText(taMessage.getText()+"\nYou :"+taSendMessage.getText());
			taSendMessage.setText("");
		}
		catch(Exception e){
		}
	}
	GuiClient() {
		super("My Chat Client - MultiClient Broadcasting");
		setSize(500,500);
		pnlBottom.setLayout(new BorderLayout(10,10));
		pnlBottom.add(new JScrollPane(taSendMessage),"Center");
		pnlBottom.add(btnSend,"East");
		btnSend.addActionListener(this);
		getContentPane().setLayout(new BorderLayout(10,10));
		getContentPane().add(new JScrollPane(taMessage),"Center");
		getContentPane().add(pnlBottom,"South");
		getContentPane().setBackground(Color.orange);
		clientSocket = new ConnecToServer(this);
		setVisible(true);
	}
	public Insets getInsets() {
		return new Insets(10,10,10,10);
	}
}

class ConnecToServer extends Thread {
	GuiClient ref;
	Socket s;
	ConnecToServer (GuiClient ref) {
		this.ref = ref;
		System.out.println("Connecting");
		try {
			s= new Socket("127.0.0.1", 3400);
			System.out.println("Connected To Client : "+s);
		}
		catch(Exception e){
			System.out.println("Error :"+e);
		}
		start();
	}
	public void run() {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));
			String mess="";
			while(true) {
				mess = br.readLine();
				ref.taMessage.setText(ref.taMessage.getText()+"\nHarshit : "+mess);
			}
		}
		catch(Exception e){
		}
	}
}