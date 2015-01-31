package onlineexam;

import javax.servlet.*;
import java.io.*;
import java.sql.*;
import javax.servlet.http.*;

public class ShowResult extends HttpServlet {
	public void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {
		HttpSession session=request.getSession(true);
		String result[]=(session.getAttribute("result")+"").split("$");
		response.setContentType("text/html");
		PrintWriter pw  = response.getWriter();
		pw.println(result[0]+"/"+result[1]);
	}
}