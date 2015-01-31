package mytags;

import javax.servlet.jsp.*;
import javax.servlet.jsp.tagext.*;
import java.io.*;
import java .util.Date;

public class ClockTag extends TagSupport
{
	Date date;
	public int doStartTag()
	{
	    date=new Date();
	    try
	    {
			JspWriter out=pageContext.getOut();
			out.print((date.getHours()-12)+" : "+date.getMinutes()+" : "+date.getSeconds());
		}
		catch(Exception ex)
		{
			System.out.println("Error : "+ex);
		}
		return(SKIP_BODY);
	}
}
