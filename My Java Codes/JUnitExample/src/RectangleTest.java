/**
 * Created by hrshtt on 1/12/17.
 */

import org.junit.Test;
import static org.junit.Assert.assertEquals;
public class RectangleTest
{
    Rectangle rect = new Rectangle();
    RectangleOptions rectOp = new RectangleOptions();

    @Test
    public void testVolume()
    {
        rect.setLength(2);
        rect.setBreadth(4);
        rect.setHeight(1);
        assertEquals(8,rectOp.getVolume(rect));
    }

    @Test
    public void testSurfaceArea()
    {
        rect.setLength(1);
        rect.setBreadth(1);
        rect.setHeight(1);
        assertEquals(4,rectOp.getSurfaceArea(rect));
    }
}
