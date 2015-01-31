

<html>
<head>
<title>
Hello World
</title>
</head>
<body>
<form action="ValidityCheck.jsp" method="post" name="form1">
<table align="center" border="1" style="background-color:#6688ff; color:#ffffff;" width="400px">
<tr>
<th colspan="2"><b><u>LOGIN</u></b></th>
</tr>
<tr>
<td>Username</td>
<td><input type="text" name="txtusername"></td>
</tr>
<tr>
<td>Password</td>
<td><input type="password" name="txtpassword"></td>
</tr>

<tr>
  <th colspan="2">
  <%
  String message=(String) session.getAttribute("message");
  if(message==null || message.equals(""))
  {
  }
  else
  out.print(message);
  %>
  </th>
</tr>
<tr>
<th colspan="2"><input type="submit" value="Login"></th>
</tr>
</table>
</form>

</body>
</html>