import java.awt.*;
import javax.swing.*;

public class GraphicsApplet extends JApplet
{
	public void paint(Graphics g)
	{
		g.setColor(Color.red);
		g.drawLine(20,20,60,60);
		g.drawRect(100,100,150,150);
	}
}