/**
 * Created by hrshtt on 1/12/17.
 */

import org.junit.runner.JUnitCore;
import org.junit.runner.Result;
import org.junit.runner.notification.Failure;

public class TestRunner
{
    public static void main(String args[])
    {
        Result result = JUnitCore.runClasses(RectangleTest.class);
        for(Failure failure : result.getFailures())
        {
            System.out.println(failure.toString());
        }
        System.out.println(result.wasSuccessful());
    }
}
