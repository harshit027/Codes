<%@ page contentType="text/html; charset=iso-8859-1" language="java" import="java.sql.*" errorPage="myerror.jsp" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
<title>My Book Management</title>
<style type="text/css">
	a:link {
		color:black;
		
	}
	a:visited {
		color:black;
		
	}
	a:hover {
		color:white;
		background-color:#6688ff;
	}
	.class1 {
		color:white;
		background-color:#6688ff;
	}
	.class2 {
		color:white;
		background-color:#dddddd;	
	}
</style>
</head>
<body>
	<table border="1" align="center" width="800px" style="font-family:Verdana, Arial, Helvetica, sans-serif; font-size:small;" bgcolor="#CCCCCC" height="500">
		<tr>
			<th style="height:125px; background-color:#6688ff; color:white;">
				<h1>PACE BUREAU<br />Book Management System</h1>
			</th>
		</tr>
		<tr>
			<td style="height:25px;" colspan="2">
				<%
					if(session.getAttribute("validity")!=null) {
						out.print("Login Id : "+session.getAttribute("userid"));
					}
				%>
			</td>
		</tr>
		<tr>
			<td style="height:325px;">
				<table border="2" cellspacing="0" cellpadding="0" height="100%;"> 
					<tr>
						<td style="width:150px; height:100%;">
							<table border="0" cellspacing="0" cellpadding="2" width="100%" height="100%" style="background-color:#dddddd">
								<tr ><td onmouseover="javascript:this.className='class1';" onmouseout="javascript:this.className='class2';" align="center" height="25px"><a href="home.jsp">Home</a></td></tr>
								<tr><td onmouseover="javascript:this.className='class1';" onmouseout="javascript:this.className='class2';"  align="center" height="25px"><a href="register.jsp">Register</a></td></tr>
								<tr><td onmouseover="javascript:this.className='class1';" onmouseout="javascript:this.className='class2';"  align="center" height="25px"><a href="newBook.jsp">New Book</a></td></tr>
								<tr><td onmouseover="javascript:this.className='class1';" onmouseout="javascript:this.className='class2';"  align="center" height="25px"><a href="viewBook.jsp">View Books</a></td></tr>
								<tr><td onmouseover="javascript:this.className='class1';" onmouseout="javascript:this.className='class2';"  align="center" height="25px"><a href="searchBook.jsp">Search Book</a></td></tr>
								<tr><td onmouseover="javascript:this.className='class1';" onmouseout="javascript:this.className='class2';"  align="center" height="25px"><a href="newTransaction.jsp">Transaction</a></td></tr>
								<tr><td onmouseover="javascript:this.className='class1';" onmouseout="javascript:this.className='class2';"  align="center" height="25px"><a href="reports.jsp">Reports</a></td></tr>
								
								<tr><td onmouseover="javascript:this.className='class1';" onmouseout="javascript:this.className='class2';"  align="center" height="25px"><a href="logout.jsp">Logout</a></td></tr>
								<tr><td></td></tr>
							</table>
						</td>
						<td width="650px" valign="top" style="background-color:#dddddd">
