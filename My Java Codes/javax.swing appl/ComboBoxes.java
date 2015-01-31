import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

class ComboBoxes extends JFrame {
  String[] description = { "Ebullient", "Obtuse",
    "Recalcitrant", "Brilliant", "Somnescent",
    "Timorous", "Florid", "Putrescent" };

  JTextField t = new JTextField(15);
  JComboBox c = new JComboBox();
  JButton b = new JButton("Add items");

  int count = 0;

  ComboBoxes() {
	  setSize(500,500);
      for(int i = 0; i < 4; i++)
      c.addItem(description[count++]);
    //t.setEditable(false);
    b.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent e){
        if(count < description.length)
          c.addItem(description[count++]);
      }
    });
    c.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent e){
        t.setText("index: "+ c.getSelectedIndex()
          + "   " + ((JComboBox)e.getSource())
          .getSelectedItem());
      }
    });

    setLayout(new FlowLayout());
    add(t);
    add(c);
    add(b);
    setVisible(true);
  }
  public static void main(String[] args) {
    new ComboBoxes();
  }
} ///:~