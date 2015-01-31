import java.net.*;
import java.awt.*;
import javax.swing.*;
import javax.swing.event.*;
import java.awt.event.*;

class SystemInfo extends JFrame implements ActionListener
{
	JPanel center,south,north;
	JButton showinfoB;
	JLabel hostipLB,hostnameLB,osnameLB,macaddressLB,nicnameLB,headerLB;
	JTextField hostipTF,hostnameTF,osnameTF,macaddressTF,nicnameTF;
	SystemInfo()
	{
		setSize(720,250);
		setLayout(new BorderLayout(20,0));
		north=new JPanel();
		north.setLayout(new FlowLayout(FlowLayout.CENTER));
		headerLB=new JLabel("System Information");
		headerLB.setFont(new Font("Verdana",0,20));
		north.add(headerLB);
		add(north,"North");

		center=new JPanel();
		center.setLayout(new GridLayout(5,2));
		hostipLB=new JLabel("IP Address");
		hostnameLB=new JLabel("Host Name");
		osnameLB=new JLabel("Operating  System");
		macaddressLB=new JLabel("MAC Address");
		nicnameLB=new JLabel("NIC");
		hostipTF=new JTextField(30);
		hostnameTF=new JTextField(30);
		osnameTF=new JTextField(30);
		macaddressTF=new JTextField(30);
		nicnameTF=new JTextField(30);
		hostipTF.setEditable(false);
		hostnameTF.setEditable(false);
		osnameTF.setEditable(false);
		macaddressTF.setEditable(false);
		nicnameTF.setEditable(false);

		center.add(hostipLB);
		center.add(hostipTF);
		center.add(hostnameLB);
		center.add(hostnameTF);
		center.add(osnameLB);
		center.add(osnameTF);
		center.add(macaddressLB);
		center.add(macaddressTF);
        center.add(nicnameLB);
        center.add(nicnameTF);
        add(center,"Center");

        south=new JPanel();
        south.setLayout(new FlowLayout(FlowLayout.CENTER));
        showinfoB=new JButton("Show Information");
        showinfoB.addActionListener(this);
        south.add(showinfoB);
        add(south,"South");

        setResizable(false);
		setVisible(true);
	}
	public static void main(String args[])
	{
		new SystemInfo();
	}
	public void actionPerformed(ActionEvent ae)
	{
		if(ae.getSource()==showinfoB)
		{
			try
			{
				InetAddress host=InetAddress.getLocalHost();
				String ipaddress=host.getHostAddress();
				hostipTF.setText(ipaddress);
				System.out.println("IP : "+ipaddress);
				String hostname=host.getHostName();
				hostnameTF.setText(hostname);
				System.out.println("Host Name : "+hostname);
			    String osname=System.getProperty("os.name");
                osnameTF.setText(osname);
                System.out.println("Operating System : "+osname);
                NetworkInterface nic=NetworkInterface.getByInetAddress(host);
                byte[] mac=nic.getHardwareAddress();
                System.out.print("MAC Address : ");
                String s = "";
	            for (int i = 0; i < mac.length; i++)
		         {
					 s+=String.format("%02X%s", mac[i], (i < mac.length - 1) ? "-" : "");
		            //System.out.printf();
		         }
                System.out.println(s+"\n");
                macaddressTF.setText(s);
                String nicname=nic.getDisplayName();
                nicnameTF.setText(nicname);
                System.out.println("NIC : "+nicname);
			}
			catch(Exception e)
			{
				e.toString();
			}
		}
	}

}