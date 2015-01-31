<%@ include file="header.jsp" %>
	<table width="60%" border="0" align="center">
		<tr>
			<th width="100%">
				<%
					String dsn = "myjspbookdb";
					String un = request.getParameter("txtusername");
					String pwd = request.getParameter("txtpassword");
					String email = request.getParameter("txtemail");
					String addr = request.getParameter("taaddress");
					String qry = "insert into users (username, passwd, emailaddress, address) values('"+un+"','"+pwd+"','"+email+"','"+addr+"')";
					try {
						Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
						Connection con  = DriverManager.getConnection("jdbc:odbc:"+dsn,"root","");
						Statement st =  con.createStatement();
						int n  = st.executeUpdate(qry);
						if(n>0) {
							out.print("Congratulation. Register Successfully");
						}
						else {
							out.print("Can not store data");
						}
					}
					catch(Exception ex) {
						throw ex;
					}
				%>
			</th>
		</tr>
	</table>
<%@ include file="footer.jsp" %>