/**
 * Created by hrshtt on 1/12/17.
 */
public class RectangleOptions
{
    public int getVolume(Rectangle rect)
    {
        return (rect.getLength()*rect.getBreadth()*rect.getHeight());
    }

    public int getSurfaceArea(Rectangle rect)
    {
        return (rect.getLength()*rect.getBreadth())+(rect.getBreadth()*rect.getHeight())+(rect.getHeight()*rect.getLength());
    }
}
