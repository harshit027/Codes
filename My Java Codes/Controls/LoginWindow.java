import java.awt.*;
import java.awt.event.*;

class LoginWindow extends Frame
{
	public static void main(String args[])
	{
		new LoginWindow();
	}

	LoginWindow()
	{
		setSize(500,500);

		setLayout(new BorderLayout(10,10));
		Label lbUsername,lbPassword,lbHeading;
		TextField tfUsername,tfPassword;
		lbUsername=new Label("Usrename");
		lbPassword=new Label("Password");
		lbHeading=new Label("L O G I N  W I N D O W",Label.CENTER);
		lbHeading.setFont(new Font("Verdana",Font.BOLD,16));
		tfUsername=new TextField();
		tfPassword=new TextField();
		Button btLogin=new Button("Login");

		Panel centerPanel=new Panel();
		centerPanel.setBackground(Color.pink);
		add(centerPanel,"Center");
		centerPanel.setLayout(new GridLayout(2,2,10,10));
		centerPanel.add(lbUsername);
		centerPanel.add(tfUsername);
		centerPanel.add(lbPassword);
		centerPanel.add(tfPassword);

		Panel bottomPanel=new Panel();
		bottomPanel.setBackground(Color.yellow);
		add(bottomPanel,"South");
		bottomPanel.setLayout(new FlowLayout(FlowLayout.CENTER,10,10));
		bottomPanel.add(btLogin);
		add(lbHeading,"North");
		setVisible(true);

		addWindowListener(new WindowAdapter()
		                                                 {
															 public void windowClosing(WindowEvent we)
															 {
																 System.exit(0);
															 }
														 });
	}
}


