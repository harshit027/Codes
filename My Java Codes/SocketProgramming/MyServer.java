import java.net.*;
import java.io.*;

class MyServer {
	public static void main(String args[]) {
		try {
			ServerSocket ss = new ServerSocket(3400);
			Socket s = ss.accept();
			BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));
			BufferedReader br1 = new BufferedReader(new InputStreamReader(System.in));
			PrintWriter pw = new PrintWriter(s.getOutputStream(),true);
			String message="Hello Client, Your Details at my comp are "+s+"";
			while(true) {
				pw.println(message);
				message = br.readLine();
				if(message.equals("bye")) {
					break;
				}
				System.out.println("Client Says :" +message);
				System.out.print("Server's Answer :");
				message =br1.readLine();
			}
			s.close();
			ss.close();
		}
		catch(Exception e) {
		}
	}
}