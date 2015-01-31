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
<form name="f1" action="saveBook.jsp" method="post">
	<br /><br /><table width="60%" border="0" align="center">
		<tr>
			<th width="100%" colspan="2" ><u><b>NEW BOOK ENTRY<br /><br /></b></u></th>
		</tr>
		<tr>
			<td>Title</td>
			<td><input type="text" name="txtbookname" /></td>
		</tr>
		<tr>
			<td>Author</td>
			<td><input type="text" name="txtbookauthor" /></td>
		</tr>
		<tr>
			<td>Price</td>
			<td><input type="text" name="txtbookprice" /></td>
		</tr>
		<tr>
			<td>Publisher</td>
			<td><input type="text" name="txtbookpublisher"  /></td>
		</tr>
		<tr>
			<td align="center" colspan="2"><input type="submit" name="btnSubmit" value="Save" /> <input type="reset" /></td>
		</tr>
	</table>
</form>
<%@ include file="footer.jsp" %>