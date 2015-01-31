import java.awt.*;
import javax.swing.*;

class TableExample extends JFrame
{
	TableExample()
	{
		setSize(600,600);
		final String heads[]={"Name","Branch","College","Year"};
		final String data[][]={
			                             {"Harshit","IT","JEC","2010"},
			                             {"Jashan","IT","JEC","2010"},
			                             {"Nishi","CS","JEC","2010"}
			                           };
        JTable table=new JTable(data,heads);
        JScrollPane jsp=new JScrollPane(table);
        getContentPane().add(jsp);
        setVisible(true);
	}
	public static void main(String args[])
	{
		new TableExample();
	}
}
