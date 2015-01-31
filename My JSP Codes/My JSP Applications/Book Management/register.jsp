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
<form name="f1" action="registeruser.jsp" method="post">
	<br /><br /><table width="60%" border="0" align="center">
		<tr>
			<th width="100%" colspan="2" ><u><b>REGISTER<br /><br /></b></u></th>
		</tr>
		<tr>
			<td>Username</td>
			<td><input type="text" name="txtusername" /></td>
		</tr>
		<tr>
			<td>Password</td>
			<td><input type="password" name="txtpassword" /></td>
		</tr>
		<tr>
			<td>Email Address</td>
			<td><input type="text" name="txtemail" /></td>
		</tr>
		<tr>
			<td>Address</td>
			<td><textarea rows="5" cols="40" name="taaddress"></textarea></td>
		</tr>
		<tr>
			<td align="center" colspan="2"><input type="submit" name="btnSubmit" value="Register" /> <input type="reset" /></td>
		</tr>
	</table>
</form>
<%@ include file="footer.jsp" %>