import java.awt.*;
import java.util.*;
class RandomColor
{
	Color randomColor;

	public void setRandomColor()
	{
		Random rnd=new Random();
		int r=rnd.nextInt(255);
		int b=rnd.nextInt(255);
		int g=rnd.nextInt(255);
		this.randomColor=new Color(r,b,g);
	}

	public Color getRandomColor()
	{
		if(this.randomColor==null)
		this.setRandomColor();
		return this.randomColor;
	}
}

