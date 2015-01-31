import java.awt.*;
import java.awt.event.*;

class MyOwnLayout extends Frame {
	Button btn[] = new Button[10];
	MyOwnLayout() {
		setLayout(null);
		int x,y, theta=36;
		setSize(500,500);
		Dimension d = getSize();
		int dx = d.width/2;
		int dy = d.height/2;
		for(int i=0;i<=9;i++) {
			x =(int) (200*Math.cos(theta));
			y =(int) (200*Math.sin(theta));
			System.out.println((dx+x)+" :: "+(dy+y));
			theta=theta+36;
			btn[i]  = new Button("PACE"+i);
			btn[i].setBounds(dx+x,dy+y, 50, 20);
			add(btn[i]);
		}
		setVisible(true);
	}
	public static void main(String args[]) {
		new MyOwnLayout ();
	}
}