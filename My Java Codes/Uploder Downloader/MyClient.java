import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.net.*;
import java.io.*;

class MyClient extends JFrame implements ActionListener{
	JLabel lblHeading = new JLabel("MY FILE CLIENT",JLabel.CENTER);
	JButton btnStartServer = new JButton("Connect to Server");
	JPanel pnlCenter = new JPanel();
	MyClient(String caption) {
		super(caption);
		setLayout(new BorderLayout());
		lblHeading.setFont(new Font("Verdana",Font.BOLD,20));
		add(lblHeading,"North");
		add(pnlCenter,"Center");
		pnlCenter.setLayout(new GridLayout(2,2));
		pnlCenter.add(btnStartServer);
		btnStartServer.addActionListener(this);
		setSize(500,300);
		setVisible(true);
	}
	public void actionPerformed(ActionEvent ae) {
		if(ae.getSource()==btnStartServer) {
			new ClientThread(this);
		}
	}
	public static void main(String args[]) {
		new MyClient("PACE BUREAU - MY FILE SENDER");
	}
}

class ClientThread extends Thread {
	MyClient ref;
	ClientThread(MyClient ref) {
		this.ref = ref;
		start();
	}
	public void run() {
		try {
			Socket s = new Socket("127.0.0.1",4000);
			System.out.println("Connected to server :" +s);
			new ClientThreadOnClient(s, ref);
		}
		catch(Exception e) {
			System.out.println("Error : "+e);
		}
	}
}

class ClientThreadOnClient extends Thread {
	MyClient ref;
	Socket s ;
	BufferedReader br ;
	PrintWriter pw;
	ClientThreadOnClient(Socket s, MyClient ref) {
		this.s = s;
		this.ref = ref;
		start();
	}
	public void run() {
		try {
			br = new BufferedReader(new InputStreamReader(s.getInputStream()));
			pw = new PrintWriter(s.getOutputStream(),true);
			String fileName ="";
			FileWriter fw =null;
			while(true) {
				String str = br.readLine();
				if(str.startsWith("FILENAME")) {
					String arr [] = str.split(":");
					fileName = arr[1];
					File f = new File("uploads/"+fileName);
					fw = new FileWriter(f);
				}
				if(str.startsWith("ENDFILE")) {
					fw.close();
					fileName="";
				}
				else {
					System.out.println("Line :" +str);
					fw.write(str+"\n");
				}
			}
		}
		catch(Exception e) {
		}
	}

}