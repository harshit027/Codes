import javax.swing.*;
import javax.swing.event.*;
import java.awt.*;
import java.awt.event.*;
import java.net.*;
import java.io.*;

class MyClientGUI extends JFrame implements ActionListener{
	public static void main(String args[])
	{
		new MyClientGUI();
	}

	JTextArea chatArea,writeArea;
	JPanel northPanel,southPanel;
	JButton logoutButton,sendButton;
	Socket s=null;
	MyClientGUI()
	{
		setSize(500,500);
		setTitle("Client");
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


					s = new Socket("127.0.0.1",3400);
					BufferedReader in=new BufferedReader(new InputStreamReader(s.getInputStream()));
					PrintWriter out = new PrintWriter(s.getOutputStream(),true);
	                String message="Hello Client, Your details at my site are "+s+"";
	                System.out.println(message);
	                while(true)
	                {
						message=in.readLine();
						if(message.equalsIgnoreCase("EXIT"))
						{
							out.println("exit");
							break;
						}
						chatArea.setText(chatArea.getText()+"\nServer : "+message);
					}
                    s.close();
                    chatArea.setText(chatArea.getText()+"\nClosing connections..........");

				}
				catch(Exception e)
				{
					e.toString();
	            }

			}

		public void actionPerformed(ActionEvent ae)
		{
				  try
				  {
				      PrintWriter out = new PrintWriter(s.getOutputStream(),true);
				      this.chatArea.setText(this.chatArea.getText()+"\nClient: "+this.writeArea.getText());
					  out.println(this.writeArea.getText());
				  	   this.writeArea.setText("");
				    }
				    catch(Exception e)
				    {
					}
			   }

}