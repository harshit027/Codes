package onlineexam;

import javax.servlet.*;
import java.io.*;
import java.sql.*;
import javax.servlet.http.*;

public class LoginCheck extends HttpServlet {
	public void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {
		String username = request.getParameter("txtusername");
		String password= request.getParameter("txtpassword");
        HttpSession session=request.getSession(true);
		try {
			Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
			Connection con  = DriverManager.getConnection("jdbc:odbc:onlineexam");
			Statement st=con.createStatement();
			ResultSet rs=st.executeQuery("select * from users");
			int flag=0;
			while(rs.next())
			{

				 String un=rs.getString(2);
			     String pwd = rs.getString(3);
			     if(username.equals(un) && password.equals(pwd))
			     {
				   flag=1;
				   break;
				  }
			  }

			  if(flag==1)
			  {
				  session.setAttribute("validity","ValidUser");

				  response.sendRedirect("test.jsp");
				  return;
			   }
			   else
			   {
			       session.setAttribute("message","Invalid Username/Password");
			       response.sendRedirect("test.jsp");
			   }

        rs.close();
	    con.close();

		}
		catch(Exception ex) {
		}

	}
}