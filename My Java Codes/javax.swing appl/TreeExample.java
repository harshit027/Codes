import java.awt.event.*;
import javax.swing.*;
import java.awt.*;
import javax.swing.tree.*;
import java.util.*;
import javax.swing.event.*;

class TreeExample extends JFrame
{
	JTree tree;
	DefaultMutableTreeNode chap1,chap2,chap3,index,a1,a2,a3,b1,b2,b3,c1,c2,c3,appendix,app1,app2,app3;
	JTextArea jta;
	TreeExample()
	{
		setSize(600,600);
		//setLayout(new BorderLayout(0,0));
		index=new DefaultMutableTreeNode("Contents");
		chap1=new DefaultMutableTreeNode ("Chapter 1");
		chap2=new DefaultMutableTreeNode ("Chapter 2");
		chap3=new DefaultMutableTreeNode ("Chapter 3");

		a1=new DefaultMutableTreeNode ("Introduction 1.1");
		a2=new DefaultMutableTreeNode ("Theory 1.2");
		a3=new DefaultMutableTreeNode ("Conclusion 1.3");
		chap1.add(a1);
		chap1.add(a2);
		chap1.add(a3);
	    b1=new DefaultMutableTreeNode ("Introduction 2.1");
		b2=new DefaultMutableTreeNode ("Theory 2.2");
		b3=new DefaultMutableTreeNode ("Conclusion 2.3");
		chap2.add(b1);
		chap2.add(b2);
		chap2.add(b3);
		c1=new DefaultMutableTreeNode ("Introduction 3.1");
		c2=new DefaultMutableTreeNode ("Theory 3.2");
	    c3=new DefaultMutableTreeNode ("Conclusion 3.3");
	    chap3.add(c1);
		chap3.add(c2);
		chap3.add(c3);

		index.add(chap1);
		index.add(chap2);
		index.add(chap3);

		appendix=new DefaultMutableTreeNode ("Appendix");
		app1=new DefaultMutableTreeNode ("Appendix 1.1");
		app2=new DefaultMutableTreeNode ("Appendix 1.2");
		app3=new DefaultMutableTreeNode ("Appendix 1.3");

		appendix.add(app1);
		appendix.add(app2);
		appendix.add(app3);

		DefaultMutableTreeNode top=new DefaultMutableTreeNode ("Main");
		top.add(index);
		top.add(appendix);
		int v= ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS;
		int h= ScrollPaneConstants.HORIZONTAL_SCROLLBAR_ALWAYS;
		tree=new JTree(top);
		JScrollPane jsp=new JScrollPane(tree,v,h);
		JPanel jp1=new JPanel();
		jp1.add(jsp);
		getContentPane().add(jp1,"West");
		JPanel jp2=new JPanel();
		jta=new JTextArea(40,40);
		jp2.add(jta);
		getContentPane().add(jp2,"East");

		setVisible(true);
	}
	public static void main(String args[])
	{
		new TreeExample();
	}
}

