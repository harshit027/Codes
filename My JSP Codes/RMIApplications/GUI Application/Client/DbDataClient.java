import java.rmi.*;
import java.rmi.server.*;
import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

class DbDataClient extends JFrame implements ActionListener{
	JButton btnRetrieve;
	JTextField jtfDeptno;
	JTable tblData;
	JPanel pnlTable = new  JPanel();
	JScrollPane jsp = new JScrollPane();
	DbDataClient () {
		JPanel pnlControls = new JPanel();
		btnRetrieve = new JButton("Retrieve");
		jtfDeptno = new JTextField(20);
		pnlControls.setLayout(new FlowLayout());
		pnlControls.add(jtfDeptno);
		pnlControls.add(btnRetrieve);
		btnRetrieve.addActionListener(this);
		getContentPane().add(pnlControls, "North");
		getContentPane().add(pnlTable, "Center");
		setSize(500,500);
		setVisible(true);
	}
	public void actionPerformed(ActionEvent ae) {
		try {
			System.setSecurityManager(new RMISecurityManager());
			String url = "rmi://localhost/";
			DbData obj = (DbData) Naming.lookup(url+"dbobj");
			String data = obj.getEmpData(Integer.parseInt(jtfDeptno.getText()));
			String arr[] = data.split("#");

			String dataarr [][] = new String[arr.length][8];
			int i=0;
			System.out.println(data+"\n\n"+arr.length);
			while(i<arr.length) {
				String arr1[] = arr[i].split(",");
				dataarr[i][0] = arr1[0];
				dataarr[i][1] = arr1[1];
				dataarr[i][2] = arr1[2];
				dataarr[i][3] = arr1[3];
				dataarr[i][4] = arr1[4];
				dataarr[i][5] = arr1[5];
				dataarr[i][6] = arr1[6];
				dataarr[i][7] = arr1[7];
				System.out.println("I = "+i);
				i++;
			}
			String dataheader [] = {"EMPNO", "ENAME", "JOB","MGR","HIREDATE","SAL","COMM","DEPTNO"};
			tblData = new JTable(dataarr, dataheader);
			pnlTable.remove(jsp);
			pnlTable.add(jsp = new JScrollPane(tblData));
			pnlTable.revalidate();
		}
		catch(Exception ex) {
			System.out.println("Error :"+ex);
		}
	}
	public static void main(String args[]) {
		new DbDataClient();
	}
}