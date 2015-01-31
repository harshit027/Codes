import java.awt.*;
import java.awt.event.*;

class MyWindowEvent2 extends Frame{
	MyWindowEvent2() {
		setTitle("Window Event");
		setBackground(Color.yellow);
		setSize(550,550);
		addWindowListener(new MyWindowAdapter());
		addMouseListener(new MyMouseAdapter(this));
		setVisible(true);
	}
	public static void main(String args[]) {
			new MyWindowEvent2();
	}
}

class MyMouseAdapter extends MouseAdapter {
	MyWindowEvent2 ref;
	MyMouseAdapter(MyWindowEvent2 ref) {
		this.ref = ref;
	}
	public void mouseClicked(MouseEvent me) {
		java.util.Random rnd = new java.util.Random();
		String s="";
		for(int i=1;i<=5;i++) {
			int n = rnd.nextInt(90);
			while(n<65) {
				n = rnd.nextInt(90);
			}
			s += (char) n;
		}
		ref.setTitle(s);
	}
}

class MyWindowAdapter extends WindowAdapter {
	public void windowClosing(WindowEvent we) {
		System.exit(0);
	}
}