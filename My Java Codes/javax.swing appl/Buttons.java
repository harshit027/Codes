
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.plaf.basic.*;
import javax.swing.border.*;

class Buttons extends JFrame {

  JButton jb = new JButton("JButton");
  BasicArrowButton
    up = new BasicArrowButton(
      BasicArrowButton.NORTH),
    down = new BasicArrowButton(
      BasicArrowButton.SOUTH),
    right = new BasicArrowButton(
      BasicArrowButton.EAST),
    left = new BasicArrowButton(
      BasicArrowButton.WEST);
    Buttons() {
    setSize(500,500);
   setLayout(new FlowLayout());
   add(jb);
   add(new JToggleButton("JToggleButton"));
   add(new JCheckBox("JCheckBox"));
   add(new JRadioButton("JRadioButton"));
    JPanel jp = new JPanel();
    jp.setBorder(new TitledBorder("Directions"));
    jp.add(up);
    jp.add(down);
    jp.add(left);
    jp.add(right);
   add(jp);
   setVisible(true);
  }
  public static void main(String[] args) {
    new Buttons();
  }
}
