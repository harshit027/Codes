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

	<table width="100%" border="0" align="center">
		<tr>
			<th width="100%" align="center" >
			<table cellpadding="4" >
			<tr>
			<td><img src="site_images/1.jpg" /></td>
			<td><img src="site_images/2.jpg" /></td>
			<td><img src="site_images/3.jpg" /></td>
			<td><img src="site_images/4.jpg" /></td>
			<td><img src="site_images/5.jpg" /></td>
			</tr>
			<tr>
			<td><img src="site_images/6.jpg" /></td>
			<td><img src="site_images/7.jpg" /></td>
			<td><img src="site_images/8.jpg" /></td>
			<td><img src="site_images/9.jpg" /></td>
			<td><img src="site_images/10.jpg" /></td>
			</tr>
			</table>
			</th>
		</tr>
	</table>
<%@ include file="footer.jsp" %>