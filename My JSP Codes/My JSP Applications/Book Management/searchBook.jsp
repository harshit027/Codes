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
<form name="f1" action="searchBookFunction.jsp" method="post">
	<br><br>
	<table width="60%" border="0" align="center" cellpadding="10">
		<tr>
			<th width="100%" colspan="2" ><u><b>SEARCH BOOK<br/><br/></b></u></th>
		</tr>
		<tr>
			<td>Book ID</td>
			<td><input type="text" name="txtbookid" /></td>
		</tr>
		<tr>
			
			<td align="center" colspan="2"><input type="submit" name="btnSubmit" value="Search" /> <input type="reset" /></td>
		</tr>
	</table>
</form>
<%@ include file="footer.jsp" %>