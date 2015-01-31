import java.awt.*;
import java.awt.event.*;

class RegistrationForm extends Frame {
	Label lblUsername, lblPassword, lblRetypePassword, lblAddress, lblEmailAddress, lblQualification, lblHeader;
	Button btnSubmit, btnReset;
	TextField tfUsername, tfPassword, tfRetypePassword, tfEmailAddress;
	TextArea taAddress;
	Choice cbQualification;
	MenuBar mb = new MenuBar();
	Menu m1 = new Menu("Users");
	Menu m2 = new Menu("Exit");
	MenuItem mi1 = new MenuItem("Register");
	MenuItem mi2 = new MenuItem("Login");
	RegistrationForm() {
		setSize(500,500);
		//memory allocation
		lblUsername = new Label("Username");
		lblPassword = new Label("Password");
		lblRetypePassword= new Label("Retype Password");
		lblAddress = new Label("Address");
		lblEmailAddress = new Label("Email Address");
		lblQualification= new Label("Qualification");
		lblHeader = new Label("R E G I S T R A T I O N   F O R M", Label.CENTER);
		btnSubmit = new Button("Register");
		btnReset = new Button("Reset");
		tfUsername = new TextField(20);
		tfPassword = new TextField(20);
		tfRetypePassword= new TextField(20);
		tfEmailAddress = new TextField(20);
		taAddress = new TextArea(5,20);
		cbQualification = new Choice();

		//Presetting
		lblHeader.setFont(new Font("Verdana",Font.BOLD, 16));
		tfPassword.setEchoChar('*');
		tfRetypePassword.setEchoChar('*');
		cbQualification.addItem("Post Graduate");
		cbQualification.addItem("Graduate");
		cbQualification.addItem("Under Graduate");

		//Setting Layouts
		setLayout(new BorderLayout(10,10));
		add(lblHeader,"North");
		Panel pnlCenter= new Panel();
		pnlCenter.setLayout(new GridLayout(6,2, 10,10));
		pnlCenter.add(lblUsername);
		pnlCenter.add(tfUsername);
		pnlCenter.add(lblPassword);
		pnlCenter.add(tfPassword);
		pnlCenter.add(lblRetypePassword);
		pnlCenter.add(tfRetypePassword);
		pnlCenter.add(lblAddress);
		pnlCenter.add(taAddress);
		pnlCenter.add(lblEmailAddress);
		pnlCenter.add(tfEmailAddress);
		pnlCenter.add(lblQualification);
		pnlCenter.add(cbQualification);
		add(pnlCenter,BorderLayout.CENTER);
		Panel pnlBottom = new Panel();
		pnlBottom.setLayout(new FlowLayout(FlowLayout.CENTER,10,10));
		pnlBottom.add(btnSubmit);
		pnlBottom.add(btnReset);
		add(pnlBottom,"South");

		setMenuBar(mb);
		mb.add(m1);
		mb.add(m2);
		m1.add(mi1);
		m1.add(mi2);

		setVisible(true);

		//for window closing
		addWindowListener(new WindowAdapter()
		                                                                       {
																				   public void windowClosing(WindowEvent we)
																				   {
																					   System.exit(0);
																				   }
																			   });

	}
	public static void main(String args[]) {
		new RegistrationForm();
	}
}