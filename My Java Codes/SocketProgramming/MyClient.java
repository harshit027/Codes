import java.net.*;
import java.io.*;

class MyClient{
	public static void main(String args[]) {
		try {
			Socket s = new Socket("127.0.0.1",3400);
			BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));
			BufferedReader br1 = new BufferedReader(new InputStreamReader(System.in));
			PrintWriter pw = new PrintWriter(s.getOutputStream(),true);
			String message="";
			while(true) {
				message = br.readLine();
				if(message.equals("bye")) {
					break;
				}
				System.out.println("Server Says :" +message);

				System.out.print("Client's Reply :");
				message =br1.readLine();
				pw.println(message);
			}
			s.close();
		}
		catch(Exception e) {
		}
	}
}