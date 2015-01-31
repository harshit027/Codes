

<%
String booklst = "<select name='slbooks'>";
try {
	String dsn = "myjspbookdb";
	//register a driver into current program for database connectivity
	Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
	//Make a connection object
	Connection con = DriverManager.getConnection("jdbc:odbc:"+dsn,"root","");
	//Create a statement object for transfering query and data
	Statement st =  con.createStatement();
	//Retrieve data from table
	String qry = "select * from books";
	ResultSet rs = st.executeQuery(qry);
	while(rs.next()) {
		booklst += "<option value='"+rs.getString(1)+"'>"+rs.getString(2)+"</option>";
	}
	rs.close();
	con.close();
}
catch(Exception ex) {
}
booklst += "</select>";
java.util.Date d = new java.util.Date();
java.text.SimpleDateFormat sdf = new java.text.SimpleDateFormat("dd/MM/yyyy");
String dt = sdf.format(d);
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
<form name="f1" action="transactionFunction.jsp" method="post">
	<br /><br /><table width="60%" border="0" align="center">
		<tr>
			<th width="100%" colspan="2" ><u><b>NEW TRANSACTION<br /><br /></b></u></th>
		</tr>
		<tr>
			<td>Book Id</td>
			<td><%= booklst %></td>
		</tr>
<!--		<tr>
			<td>Member Id</td>
			<td><input type="text" name="txtmemberid" /></td>
		</tr>
-->		<tr>
			<td>Type</td>
			<td>
				<select name="sltype">
					<option value="I">Issue</option>
					<option value="R">Return</option>
				</select>
			</td>
		</tr>
		<tr>
		<td>
		Date
		</td>
		<td>
		<input type="text" name="txtdate" value="<%= dt %>"  />
		</td>
		</tr>
		<tr>
			<td align="center" colspan="2"><input type="submit" name="btnSubmit" value="Process" /> <input type="reset" value="Cancel"/></td>
		</tr>
	</table>
</form>
<%@ include file="footer.jsp" %>