import java.net.*;
import java.io.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;

class GuiServer extends JFrame implements ActionListener{
	JTextArea taMessage = new JTextArea(10,40);
	JTextArea taSendMessage = new JTextArea(4,40);
	JButton btnSend = new JButton("Send");
	JPanel pnlBottom = new JPanel();
	StartServer obj;
	Vector vec = new Vector();
	public static void main(String args[]) {
		new GuiServer();
	}
	public void actionPerformed(ActionEvent ae) {
		try {
			int i=0, n = vec.size();
			for(i=0;i<=n-1;i++) {
				Socket temp = (Socket) vec.get(i);
				PrintWriter pw = new PrintWriter(temp.getOutputStream(),true);
				pw.println(taSendMessage.getText());
			}
			taMessage.setText(taMessage.getText()+"\nServer :"+taSendMessage.getText());
			taSendMessage.setText("");
		}
		catch(Exception e){
		}
	}
	GuiServer() {
		super("My Chat Server - MultiClient Broadcasting");
		setSize(500,500);
		pnlBottom.setLayout(new BorderLayout(10,10));
		pnlBottom.add(new JScrollPane(taSendMessage),"Center");
		pnlBottom.add(btnSend,"East");
		btnSend.addActionListener(this);
		getContentPane().setLayout(new BorderLayout(10,10));
		getContentPane().add(new JScrollPane(taMessage),"Center");
		getContentPane().add(pnlBottom,"South");
		getContentPane().setBackground(Color.orange);
		setVisible(true);
		obj = new StartServer(this);
	}
	public Insets getInsets() {
		return new Insets(10,10,10,10);
	}
}

class StartServer extends Thread {
	ServerSocket ss =null;
	GuiServer ref;
	StartServer(GuiServer ref) {
		this.ref = ref;
		start();
	}
	public void run() {
		try {
			ss = new ServerSocket(3400);
			while(true) {
				System.out.println("Waiting for Client ...");
				Socket s = ss.accept();
				ref.vec.add(s);
				new ChildThreadOnServer(ref, s);
			}
		}
		catch(Exception e) {
		}
	}
}

class ChildThreadOnServer extends Thread {
	GuiServer ref;
	Socket s;
	ChildThreadOnServer(GuiServer ref, Socket s) {
		this.ref = ref;
		this.s = s;
		start();
	}
	public void run() {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));
			String mess="";
			while(true) {
				mess = br.readLine();
				ref.taMessage.setText(ref.taMessage.getText()+"\nClient : "+mess);
			}
		}
		catch(Exception e){
		}
	}
}