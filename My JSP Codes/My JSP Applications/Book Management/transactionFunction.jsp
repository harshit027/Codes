
<%@ include file="header.jsp" %>
	<%
		String bookid = request.getParameter("slbooks");
		String memberid = (String) session.getAttribute("userid");
		String type = request.getParameter("sltype");
		String doi = request.getParameter("txtdate");
		String []arr = doi.split("/");
		doi = arr[2]+"-"+arr[1]+"-"+arr[0];
		String qry = "insert into transactions(bookid, memberid, type,trdate) values(?,?,?,?)";
		//out.print(qry +"<br>"+bookid+", "+memberid+", "+type+", "+doi);
		try {
			Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
			Connection con = DriverManager.getConnection("jdbc:odbc:myjspbookdb","root","");
			PreparedStatement ps = con.prepareStatement(qry);
			ps.setInt(1, Integer.parseInt(bookid));
			ps.setInt(2, Integer.parseInt(memberid));
			ps.setString(3, type);
			ps.setString(4,doi);
			if(ps.executeUpdate()>0)
			{
			   out.print("Transaction Completed");
			}
			con.close();
		}
		catch(Exception ex) {
			out.print("Error :"+ex);
		}
	%>
<%@ include file="footer.jsp" %>