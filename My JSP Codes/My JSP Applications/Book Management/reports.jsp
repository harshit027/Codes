
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
<h3 align="center"><u><b>REPORTS</b></u></h3>
<table width="60%" border="0" align="center">
		<tr valign="top">
			<th width="100%" valign="top">
				
<%
String dsn = "myjspbookdb";
String query="select * from transactions";
try
{
   Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
   Connection con  = DriverManager.getConnection("jdbc:odbc:"+dsn,"root","");
   Statement st =  con.createStatement();
   ResultSet rs=st.executeQuery(query);
   String reports="<table cellspacing='0' border='1' style='background-color:white;' width='500px'>";
   reports+="<tr style='background-color:#6688ff; color:white;'><td>BookId</td><td>Title</td><td>Author</td><td>Price</td><td>Publisher</td></tr>";
   
   while(rs.next())
   {
      String trid=rs.getString(1);
	  String bookid=rs.getString(2);
	  String memberid=rs.getString(3);
	  String type=rs.getString(4);
	  String trdate=rs.getString(5);
	  reports+="<tr align='center' >";
	  reports+="<td>"+trid+"</td>";
	  reports+="<td>"+bookid+"</td>";
	  reports+="<td>"+memberid+"</td>";
	  reports+="<td>"+type+"</td>";
	  reports+="<td>"+trdate+"</td>";
	  reports+="</tr>";
	}
	reports+="</table>";
	out.print(reports);
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