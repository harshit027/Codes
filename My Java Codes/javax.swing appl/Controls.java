import javax.swing.*;
import java.awt.*;
class Controls extends JFrame
{
	public static void main(String args[])
	{
		new Controls();
	}

	Controls ()
	{

		setSize(500,500);
		setLayout(new BorderLayout());
		JPanel jpnl1=new JPanel();
		jpnl1.setLayout(new FlowLayout(FlowLayout.CENTER));
		JLabel jlbl=new JLabel("Name");
		JTextField jtf=new JTextField(15);
		JButton jbtn=new JButton("Register");
		jbtn.setBackground(Color.yellow);
		JMenuBar jmenu=new JMenuBar();
		JMenu jm1=new JMenu("File");
		JMenu jm2=new JMenu("Edit");
		jmenu.add(jm1);
		jmenu.add(jm2);
		JMenuItem jmi11=new JMenuItem("New");
		JMenuItem jmi12=new JMenuItem("Save");
		JMenuItem jmi13=new JMenuItem("SaveAs");
		JMenuItem jmi21=new JMenuItem("Copy");
		JMenuItem jmi22=new JMenuItem("Paste");
		jm1.add(jmi11);
		jm1.add(jmi12);
		jm1.add(jmi13);
		jm2.add(jmi21);
		jm2.add(jmi22);
		setJMenuBar(jmenu);

		jpnl1.add(jlbl);
		jpnl1.add(jtf);
		jpnl1.add(jbtn);
        add(jpnl1,"North");

        JScrollBar jscr=new JScrollBar();
        add(jscr,"East");
		setVisible(true);
	}
}
