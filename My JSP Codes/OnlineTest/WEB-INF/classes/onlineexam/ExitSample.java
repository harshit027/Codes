package onlineexam;

import javax.servlet.*;
import java.io.*;
import java.sql.*;
import javax.servlet.http.*;

public class ExitSample extends HttpServlet {
	public void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {
		HttpSession session=request.getSession(true);
		session.removeAttribute("questionParameters");
		session.removeAttribute("counter");
		response.sendRedirect("test.jsp");
	}
}