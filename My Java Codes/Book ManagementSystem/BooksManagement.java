import java.sql.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class AddPanel extends JPanel {
	String strCaptions[] = {"Book No", "Book Title", "Book Author", "Book Price", "Book Publisher"};
	JLabel lblCaptions[] = null;
	JTextField tfValues [] = null;
	AddPanel() {
		setLayout(new GridLayout(5,2));
		lblCaptions = new JLabel[5];
		tfValues = new JTextField[5];
		for(int i=0;i<=4;i++) {
			lblCaptions[i] = new JLabel(strCaptions[i]);
			add(lblCaptions[i]);
			tfValues[i] = new JTextField(20);
			add(tfValues[i]);
		}
	}
}

 class BooksManagement extends JFrame implements ActionListener{
	JMenuBar mb;
	JMenu options;
	JMenuItem mnuAdd, mnuEdit, mnuDelete, mnuSave,mnuView, mnuExit;
	BooksManagement() {
		setSize(300,250);
		mb = new JMenuBar();
		options = new JMenu("Options");
		mnuAdd = new JMenuItem("Add New Book");
		mnuEdit = new JMenuItem("Edit Book");
		mnuDelete = new JMenuItem("Delete Book");
		mnuSave = new JMenuItem("Save Book");
		mnuView =new JMenuItem("View Books");
		mnuExit = new JMenuItem("Exit");
		mnuAdd.addActionListener(this);
		mnuEdit.addActionListener(this);
		mnuDelete.addActionListener(this);
		mnuSave.addActionListener(this);
		mnuView.addActionListener(this);
		mnuExit.addActionListener(this);
		options.add(mnuAdd);
		options.add(mnuEdit);
		options.add(mnuDelete);
		options.add(mnuSave);
		options.add(mnuView);
		options.add(mnuExit);
		mb.add(options);
		setJMenuBar(mb);
		getContentPane().setLayout(new BorderLayout());
		getContentPane().add(new JLabel("BOOK MANAGEMENT SYSTEM",JLabel.CENTER),"North");

		//setSize(600,600);
		setVisible(true);
	}
	AddPanel pnlAdd;
	public void actionPerformed(ActionEvent ae) {
		if(ae.getSource() == mnuAdd) {
			pnlAdd = new AddPanel();
			this.add(pnlAdd,"Center");
			Dimension d = getSize();
			int w = (int) d.getWidth();
			int h = (int) d.getHeight();
			setSize(w+1, h+1);
			setSize(w-1, h-1);
			this.invalidate();
		}
		else if(ae.getSource() == mnuAdd) {
		}
		else if(ae.getSource() == mnuEdit) {
		}
		else if(ae.getSource() == mnuDelete) {
		}
		else if(ae.getSource() == mnuSave) {
			try {
				String dsn = "book_database";
				String qry = "insert into book (bno, btitle, bauthor, bprice, bpublisher) values( ?, ? ,?, ?, ?)";
				Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
				Connection con = DriverManager.getConnection("jdbc:odbc:"+dsn);
				PreparedStatement pst = con.prepareStatement(qry);
				pst.setInt(1, Integer.parseInt(pnlAdd.tfValues[0].getText()));
				pst.setString(2, pnlAdd.tfValues[1].getText());
				pst.setString(3, pnlAdd.tfValues[2].getText());
				pst.setDouble(4, Double.valueOf(pnlAdd.tfValues[3].getText()).doubleValue());
				pst.setString(5, pnlAdd.tfValues[4].getText());

				int count=pst.executeUpdate();
				if(count>0) {
					JOptionPane.showMessageDialog(this,"Record Saved Successfully");
				}
				else {
					JOptionPane.showMessageDialog(this,"Some Error occured");
				}
				con.close();
			}
			catch(Exception e) {
				JOptionPane.showMessageDialog(this,"Error "+e);
			}
		}
		else if(ae.getSource() == mnuExit) {
			System.exit(0);
		}

		if(ae.getSource()==mnuView)
		{
			try
			{
				Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
				Connection con=DriverManager.getConnection("jdbc:odbc:book_database");
				Statement st=con.createStatement();
				ResultSet rs=st.executeQuery("select * from book");
				while(rs.next())
				{
					System.out.print(rs.getString(1)+"------");
					System.out.print(rs.getString(2)+"------");
					System.out.print(rs.getString(3)+"------");
					System.out.print(rs.getString(4)+"------");
					System.out.println(rs.getString(5));
				}
				rs.close();
				con.close();
			}
			catch(Exception e)
			{
				e.toString();
			}
		}


	}
	public static void main(String args[]) {
		new BooksManagement();
	}
}