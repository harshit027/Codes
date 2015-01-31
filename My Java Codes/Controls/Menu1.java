//creating labels

import java.awt.*;
import java.awt.event.*;

class Menu1 extends Frame
{
	Menu1()
	{
		setSize(500,500);
		setVisible(true);
		setTitle("Menu Example");

		addWindowListener(new WindowAdapter()
		                                                 {
															 public void windowClosing(WindowEvent we)
															 {
																 System.exit(0);
															 }
														 });


		MenuBar mb=new MenuBar();
		Menu m1=new Menu("File");
		Menu m2=new Menu("Edit");
		Menu m3=new Menu("Tools");

		MenuItem m11=new MenuItem("New");
		MenuItem m12=new MenuItem("Save");
		MenuItem m13=new MenuItem("Save As");
		MenuItem m21=new MenuItem("Undo");
		MenuItem m22=new MenuItem("Redo");
		MenuItem m31=new MenuItem("Spell");
		MenuItem m32=new MenuItem("Sort");

		setMenuBar(mb);
		mb.add(m1);
		mb.add(m2);
		mb.add(m3);
		m1.add(m11);
		m1.add(m12);
		m1.add(m13);
		m2.add(m21);
		m2.add(m22);
		m3.add(m31);
		m3.add(m32);
	}
	public static void main(String args[])
	{
		new Menu1();
	}
}
