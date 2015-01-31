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
public class FlexibleHeadingTag extends TagSupport {
	String fontColor="#00FF00";
	String fontName="verdana";
	String fontSize="12pt";
	public void setFontColor(String fontColor) {
		this.fontColor=fontColor;
	}
	public void setFontSize(String fontSize) {
		this.fontSize=fontSize;
	}
	public void setFontName(String fontName) {
		this.fontName=fontName;
	}
	public int doStartTag() {
		try {
			JspWriter out = pageContext.getOut();
			out.print("<span style='color:"+fontColor+";font-size:"+fontSize+";font-family:"+fontName+";'>");
		} catch(IOException ioe) {
			System.out.println("Error in ExampleTag: " + ioe);
		}
		return(EVAL_BODY_INCLUDE);
	} //function doStartTag Ends Here
	public int doEndTag() {
		try {
			JspWriter out = pageContext.getOut();
			out.print("</span>");
		}
		catch(IOException ioe) {
			System.out.println("Error in FlexibleHeadingTag"+ioe);
		}
		return (EVAL_PAGE);
	}
} //class ExampleTag Ends Here
