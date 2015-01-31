
package mytags;

import javax.servlet.jsp.*;
import javax.servlet.jsp.tagext.*;
import java.io.*;

/** Very simple JSP tag that just inserts a string
* ("Custom tag example...") into the output.
* The actual name of the tag is not defined here;
* that is given by the Tag Library Descriptor (TLD)
* file that is referenced by the taglib directive
* in the JSP file.
*/
public class ExampleTag extends TagSupport {
	public int doStartTag() {
		try {
			JspWriter out = pageContext.getOut();
			out.print("<h1>PACE BUREAU</h1>");
		} catch(IOException ioe) {
			System.out.println("Error in ExampleTag: " + ioe);
		}
		return(SKIP_BODY);
	} //function doStartTag Ends Here
} //class ExampleTag Ends Here
