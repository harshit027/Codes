package onlineexam;

import javax.servlet.*;
import java.io.*;
import java.sql.*;
import javax.servlet.http.*;

public class EndTest extends HttpServlet {
	public void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {
		HttpSession session=request.getSession(true);
		session.invalidate();
		response.sendRedirect("test.jsp");
	}
}