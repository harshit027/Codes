package myservlet_examples;
import javax.servlet.*;
import java.io.*;


public class FirstServlet extends GenericServlet {
	public void service(ServletRequest sreq, ServletResponse sresp) throws IOException, ServletException {
		sresp.setContentType("text/html");
		PrintWriter pw = sresp.getWriter();
		pw.println("<h1>PACE BUREAU</h1><hr>Welcome in world of Servlets");
		pw.close();
	}
}