import java.awt.*;
import javax.swing.*;
import javax.swing.border.*;

class GridBagExample extends JFrame
{
	GridBagExample()
	{
		setSize(600,600);
		setLayout(new BorderLayout());
		JPanel p1=new JPanel();
		GridBagLayout gb=new GridBagLayout();
		GridBagConstraints gbc=new GridBagConstraints();
		gbc.gridwidth=1;
		gbc.gridheight=1;
		gbc.weightx=1;
        gbc.weighty=1;
        gbc.ipadx=10;
        gbc.ipady=10;
		p1.setLayout(gb);
		JLabel name=new JLabel("Name");
		JLabel phone=new JLabel("Phone");
		JLabel address=new JLabel("Address");
		JTextField nameTF=new JTextField(20);
		JTextField phoneTF=new JTextField(20);
		JTextField addressTF=new JTextField(20);
		JButton submit=new JButton("Submit");

		gbc.gridx=5;
		gbc.gridy=5;
		p1.add(name,gbc);

		gbc.gridx=10;
		gbc.gridy=5;
		p1.add(nameTF,gbc);

		gbc.gridx=5;
		gbc.gridy=10;
		p1.add(phone,gbc);

		gbc.gridx=10;
		gbc.gridy=10;
		p1.add(phoneTF,gbc);

		gbc.gridx=5;
		gbc.gridy=15;
		p1.add(address,gbc);

		gbc.gridx=10;
		gbc.gridy=15;
		p1.add(addressTF,gbc);

		gbc.gridx=15;
		gbc.gridy=20;
		p1.add(submit,gbc);

		Border etched=BorderFactory.createEtchedBorder();
		Border titled=BorderFactory.createTitledBorder(etched,"Panel");
		p1.setBorder(titled);
		add(p1,"North");
		setVisible(true);
	}
	public static void main(String args[])
	{
		new GridBagExample();
	}
}