<%@ page contentType="text/html; charset=iso-8859-1" language="java" import="java.sql.*" errorPage="" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
<title>Untitled Document</title>
</head>

<body>
<%
String username=(String) request.getParameter("txtusername");
String password=(String) request.getParameter("txtpassword");
try
{
   Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
   Connection con =DriverManager.getConnection("jdbc:odbc:userdsn");
   Statement st=con.createStatement();
   ResultSet rs=st.executeQuery("select * from users");
   int flag=0;
   while(rs.next())
   {
       
       if(username.equals(rs.getString(2)) && password.equals(rs.getString(3)))
       {
	     flag=1; 
       }  
    }
	
	if(flag==1)
	{
	     session.setAttribute("validity","ValidUser");
         response.sendRedirect("SessionEg11.jsp");
    }
	else
	{
	     session.setAttribute("message","Invalid Username/Password");
         response.sendRedirect("SessionEg1.jsp");
    }

	
	
	rs.close();
	con.close();
}
catch(Exception e)
{
  out.print(e);
}

%>
</body>
</html>
