import java.awt.*;
import java.awt.event.*;

class MyWindowEvent3 extends Frame implements KeyListener{
	MyWindowEvent3() {
		setTitle("Window Event - Key Listener");
		setBackground(Color.yellow);
		setSize(550,550);
		setVisible(true);
		addKeyListener(this);
		addWindowListener(new WindowAdapter() {
												public void windowClosing(WindowEvent we) {
													System.exit(0);
												}
											}
										);
	}
	public void keyPressed(KeyEvent ke) {
	}
	public void keyReleased(KeyEvent ke) {
	}
	String s = "pace - ";
	public void keyTyped(KeyEvent ke) {
		if(ke.getKeyChar() == KeyEvent.VK_ENTER) {
			s=  "Pace - ";
		}
		else {
			s+=ke.getKeyChar();
		}
		setTitle(s);
	}
	public static void main(String args[]) {
			new MyWindowEvent3();
	}
}
