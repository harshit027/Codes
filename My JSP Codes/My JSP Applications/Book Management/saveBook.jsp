
<%@ include file="header.jsp" %>
	<table width="60%" border="0" align="center">
		<tr>
			<th width="100%">
				<%
					String dsn = "myjspbookdb";
					String bname = request.getParameter("txtbookname");
					String bauthor = request.getParameter("txtbookauthor");
					String bprice = request.getParameter("txtbookprice");
					String bpublisher = request.getParameter("txtbookpublisher");
					String qry = "insert into books (bookname, bookauthor, bookprice, bookpublisher) values('"+bname+"','"+bauthor+"',"+bprice+",'"+bpublisher+"')";
					try {
						Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
						Connection con  = DriverManager.getConnection("jdbc:odbc:"+dsn,"root","");
						Statement st =  con.createStatement();
						int n  = st.executeUpdate(qry);
						if(n>0) {
							out.print("Book Saved Successfully");
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