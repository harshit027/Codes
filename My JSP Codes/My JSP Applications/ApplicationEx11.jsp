<%@ page contentType="text/html; charset=iso-8859-1" language="java" import="java.sql.*" errorPage="" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
<title>Untitled Document</title>
</head>

<body>
<%
out.print("Session Id : "+session.getId());
out.print("<br>");
out.print("Author : "+application.getAttribute("Author")+"");
out.print("<br>");
out.print("Style : "+session.getAttribute("Style")+"");
String count=(String) application.getAttribute("Counter");
int a=Integer.parseInt(count);
a++;
out.print("<br>Page Visited : "+a+" times");
application.setAttribute("Counter",a+"");
%>
</body>
</html>
