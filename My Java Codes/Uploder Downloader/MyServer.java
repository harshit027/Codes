import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.net.*;
import java.io.*;

class MyServer extends JFrame implements ActionListener{
	JLabel lblHeading = new JLabel("MY FILE SERVER",JLabel.CENTER);
	JButton btnStartServer = new JButton("Start Server");
	JButton btnSelectFile = new JButton("Browse...");
	JButton btnSend = new JButton("Send File");
	JTextField tfFileName = new JTextField(20);
	JPanel pnlCenter = new JPanel();
	JPanel pnlSouth = new JPanel();
	JFileChooser jfc = new JFileChooser();
	String filedata = "";
	ServerThread st =null;
	MyServer(String caption) {
		super(caption);
		setLayout(new BorderLayout());
		lblHeading.setFont(new Font("Verdana",Font.BOLD,20));
		add(lblHeading,"North");
		add(pnlCenter,"Center");
		add(pnlSouth,"South");
		pnlCenter.setLayout(new GridLayout(2,2));
		pnlCenter.add(tfFileName);
		pnlCenter.add(btnSelectFile);
		pnlCenter.add(btnStartServer);
		pnlCenter.add(btnSend);
		btnSelectFile.addActionListener(this);
		btnStartServer.addActionListener(this);
		btnSend.addActionListener(this);
		setSize(500,300);
		setVisible(true);
	}
	public void actionPerformed(ActionEvent ae) {
		if(ae.getSource()==btnSelectFile) {
			jfc.showOpenDialog(this);
			File file = jfc.getSelectedFile();
			tfFileName.setText(file.getName());
			try {
				FileReader fr = new FileReader(file.getPath());
				BufferedReader br = new BufferedReader(fr);
				while(true) {
					String line = br.readLine();
					if(line == null)break;
					filedata+=line+"\n";
				}
				br.close();
			}
			catch(Exception e){
			}
		}
		else if(ae.getSource()==btnSend) {
			if(st==null) {
				JOptionPane.showMessageDialog(this,"Server kaun chaloo karega");
				return;
			}
			if(filedata.equals("") ) {
				JOptionPane.showMessageDialog(this,"Kyon re file kaun select karega");
				return;
			}
			try {
				PrintWriter pw = new PrintWriter(st.s.getOutputStream(),true);
				pw.println("FILENAME:"+tfFileName.getText());
				pw.println(filedata);
				pw.println("ENDFILE");
				pw.close();
			}
			catch(Exception e){
			}
		}
		else if(ae.getSource()==btnStartServer) {
			st = new ServerThread(this);
		}
	}
	public static void main(String args[]) {
		new MyServer("PACE BUREAU - MY FILE SENDER");
	}
}

class ServerThread extends Thread {
	MyServer ref;
	Socket s=null;
	ServerThread(MyServer ref) {
		this.ref = ref;
		start();
	}
	public void run() {
		try {
			ServerSocket ss = new ServerSocket(4000);
			JOptionPane.showMessageDialog(ref,"Server Started");
			while(true) {
				s = ss.accept();
				new ClientThreadOnServer(s, ref);
			}
		}
		catch(Exception e) {
			System.out.println("Error : "+e);
		}
	}
}

class ClientThreadOnServer extends Thread {
	MyServer ref;
	Socket s ;
	BufferedReader br ;
	PrintWriter pw;
	ClientThreadOnServer(Socket s, MyServer ref) {
		this.s = s;
		this.ref = ref;
		start();
	}
	public void run() {
		try {
			br = new BufferedReader(new InputStreamReader(s.getInputStream()));
			pw = new PrintWriter(s.getOutputStream(),true);
			while(true) {

			}
		}
		catch(Exception e) {
		}
	}

}