<%@ page contentType="text/html; charset=iso-8859-1" language="java" import="java.sql.*" errorPage="myerror.jsp" %>
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
   Connection con =DriverManager.getConnection("jdbc:odbc:myjspbookdb");
   Statement st=con.createStatement();
   ResultSet rs=st.executeQuery("select * from users");
   int flag=0;
   int userid=0;
   while(rs.next())
   {
	   	userid = rs.getInt(1);
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
	     session.setAttribute("userid",userid+"");
         response.sendRedirect("home.jsp");
		 return;
    }
	else
	{
	     session.setAttribute("message","Invalid Username/Password");
         response.sendRedirect("home.jsp");
    }

	
	
	rs.close();
	con.close();
}
catch(Exception e)
{
  throw(e);
}

%></body>
</html>
