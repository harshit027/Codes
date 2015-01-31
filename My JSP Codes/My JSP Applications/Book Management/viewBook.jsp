<%
String authentication=(String) session.getAttribute("validity");
if(authentication!=null)
{
   if(authentication.equals("ValidUser"))
   {
     
   }
}
else
response.sendRedirect("login.jsp");

%>

<%@ include file="header.jsp" %>
<h3 align="center"><u><b>BOOK LIST</b></u></h3>
<table width="60%" border="0" align="center">
		<tr valign="top">
			<th width="100%" valign="top">
				
<%
String dsn = "myjspbookdb";
String query="select * from books";
try
{
   Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
   Connection con  = DriverManager.getConnection("jdbc:odbc:"+dsn,"root","");
   Statement st =  con.createStatement();
   ResultSet rs=st.executeQuery(query);
   String booklist="<table cellspacing='0' border='1' style='background-color:white;' width='500px'>";
   booklist+="<tr style='background-color:#6688ff; color:white;'><td>BookId</td><td>Title</td><td>Author</td><td>Price</td><td>Publisher</td></tr>";
   
   while(rs.next())
   {
      String bookid=rs.getString(1);
	  String bookname=rs.getString(2);
	  String bookauthor=rs.getString(3);
	  String bookprice=rs.getString(4);
	  String bookpublisher=rs.getString(5);
	  booklist+="<tr align='center' >";
	  booklist+="<td>"+bookid+"</td>";
	  booklist+="<td>"+bookname+"</td>";
	  booklist+="<td>"+bookauthor+"</td>";
	  booklist+="<td>"+bookprice+"</td>";
	  booklist+="<td>"+bookpublisher+"</td>";
	  booklist+="</tr>";
	}
	booklist+="</table>";
	out.print(booklist);
}
catch(Exception ex)
{
   throw ex;
}
%>

				
			</th>
		</tr>
	</table>
<%@ include file="footer.jsp" %>