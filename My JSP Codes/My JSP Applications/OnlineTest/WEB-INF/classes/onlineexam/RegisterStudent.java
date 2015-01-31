package onlineexam;

import javax.servlet.*;
import java.io.*;
import java.sql.*;
import javax.servlet.http.*;

public class RegisterStudent extends HttpServlet {
	public void doPost(HttpServletRequest req, HttpServletResponse resp) throws IOException, ServletException {
		String sn = req.getParameter("txtname");
		String pwd = req.getParameter("txtpassword");
		String dob  = req.getParameter("txtdob");
		String email  = req.getParameter("txtemail");
		String addr = req.getParameter("txtaddress");
		String phone  = req.getParameter("txtphone");
		String qry = "insert into users (username, passwd, address, phonenumber, emailaddress, dateofbirth) values (?, ?, ?, ?, ?, ?)";
		try {
			Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
			Connection con  = DriverManager.getConnection("jdbc:odbc:onlineexam");
			PreparedStatement ps = con.prepareStatement(qry);
			ps.setString(1, sn);
			ps.setString(2, pwd);
			ps.setString(3, addr);
			ps.setString(4, phone);
			ps.setString(5, email);
			ps.setString(6, dob);
			int n = ps.executeUpdate();
			resp.setContentType("text/html");
			PrintWriter pw  = resp.getWriter();
			if(n>0) {
				pw.println("<h1 style='color:green;'>User Data Stored</h1>");
			}
			else {
				pw.println("<h1 style='color:red;'>Invalid Data, Data Storage Failed</h1>");
			}
		}
		catch(Exception ex) {
		}
	}
}