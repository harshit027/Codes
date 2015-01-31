import javax.swing.*;
import java.awt.*;


public class BoxLayout1 extends Frame {
    BoxLayout1() {
		setSize(500,500);
    Panel pv = new Panel();
    pv.setLayout(
      new BoxLayout(pv, BoxLayout.Y_AXIS));
    for(int i = 0; i < 5; i++)
      pv.add(new Button("" + i));
    Panel ph = new Panel();
    ph.setLayout(
      new BoxLayout(ph, BoxLayout.X_AXIS));
    for(int i = 0; i < 5; i++)
      ph.add(new Button("" + i));

 add(pv,BorderLayout.EAST);
 add(ph,BorderLayout.SOUTH);
    setVisible(true);
  }
  public static void main(String[] args) {
    new BoxLayout1();
}
}