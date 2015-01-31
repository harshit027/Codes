<%@ include file="header.jsp" %>
<br /><br /><table width="60%" border="0" align="center">
<tr>
<td>
<%
String dsn="myjspbookdb";
String query="select * from books where bookid="+request.getParameter("txtbookid");
try
{
Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
Connection con=DriverManager.getConnection("jdbc:odbc:"+dsn,"root","");
Statement st=con.createStatement();
ResultSet rs=st.executeQuery(query);
if(rs.next())
{
String bookRecord="<table width='400px' border='1' style='background-color:white;' cellspacing='0'>";
bookRecord+="<tr style='background-color:#6688ff; color:white;'><td colspan='2' align='center'><b>RECORD DETAILS</b></td></tr>";
bookRecord+="<tr><td>Book Id</td><td>"+rs.getString(1)+"</td></tr>";
bookRecord+="<tr><td>Title</td><td>"+rs.getString(2)+"</td></tr>";
bookRecord+="<tr><td>Author</td><td>"+rs.getString(3)+"</td></tr>";
bookRecord+="<tr><td>Price</td><td>"+rs.getString(4)+"</td></tr>";
bookRecord+="<tr><td>Publisher</td><td>"+rs.getString(5)+"</td></tr>";
bookRecord+="</table>";
out.print(bookRecord);
}
else
out.print("<h3 align='center'>No records found</h3>");
}
catch(Exception ex)
{
throw ex;
}
%>
</td>
</tr>
</table>
<%@ include file="footer.jsp" %>
