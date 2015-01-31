import javax.swing.*;
import javax.swing.event.*;
import java.awt.*;
import java.awt.event.*;
import java.net.*;
import java.io.*;

class MyServerGUI extends JFrame implements ActionListener {
	public static void main(String args[]) {
		new MyServerGUI();

	}

		JTextArea chatArea,writeArea;
		JPanel northPanel,southPanel;
		JButton logoutButton,sendButton;
		Socket s=null;
		MyServerGUI()
		{
			setSize(500,500);
			setTitle("Server");
			getContentPane().setLayout(new BorderLayout(10,10));
			northPanel=new JPanel();
			northPanel.setLayout(new FlowLayout(FlowLayout.RIGHT));
			logoutButton=new JButton("LOGOUT");
			northPanel.add(logoutButton);
			getContentPane().add(northPanel,"North");

			chatArea=new JTextArea(20,40);
			getContentPane().add(new JScrollPane(chatArea),"Center");
			getContentPane().add(chatArea,"Center");
	        getContentPane().add(new JScrollPane(chatArea) ,"Center");

		    southPanel=new JPanel();
			southPanel.setLayout(new BorderLayout(10,10));
			sendButton=new JButton("SEND");
			sendButton.addActionListener(this);
			writeArea=new JTextArea(5,40);
			sendButton.setBackground(Color.yellow);


			southPanel.add(writeArea,"Center");
		    southPanel.add(new JScrollPane(writeArea),"Center");
			southPanel.add(sendButton,"East");
			getContentPane().add(southPanel,"South");
		    getContentPane().setBackground(Color.orange);
			setVisible(true);

			try {

						ServerSocket ss = new ServerSocket(3400);
						System.out.println("Server Started");
						s = ss.accept();
                        String message="";
						BufferedReader in=new BufferedReader(new InputStreamReader(s.getInputStream()));
                        PrintWriter out = new PrintWriter(s.getOutputStream(),true);
                        while(true)
                        {
							message=in.readLine();
							if(message.equalsIgnoreCase("EXIT"))
							{
								out.println("exit");
								break;
							}
							chatArea.setText(chatArea.getText()+"\nClient : "+message);
						}
						s.close();
                        ss.close();
                       chatArea.setText(chatArea.getText()+"\nClosing connections..........");

					}
					catch(Exception e)
					{
						e.toString();
		            }

		}

		public void actionPerformed(ActionEvent ae)
		{

              {
				  try
				  {
				         PrintWriter out = new PrintWriter(s.getOutputStream(),true);
					     out.println(this.writeArea.getText());
				         this.chatArea.setText(this.chatArea.getText()+"\nServer : "+this.writeArea.getText());
				  	     this.writeArea.setText("");

				    }
				    catch(Exception e)
				    {
					}
			   }

		}

}