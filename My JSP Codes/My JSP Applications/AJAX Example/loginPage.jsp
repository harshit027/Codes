<%@ page contentType="text/html; charset=iso-8859-1" language="java" import="java.sql.*" errorPage="" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
<title>Untitled Document</title>

<script type="text/javascript" src="ajaxScript.js">

</script>
</head>

<body onload="startCounter()">
<form name="form1" method="get">
<div id="counterDiv">
</div><br /><br />
<table width="400px;" align="center" border="2" cellspacing="0" cellpadding="5">
<tr>
<th colspan="2">Login</th>
</tr>
<tr>
<td>Username</td>
<td><input type="text" name="txtusername" id="txtusername" /></td>
</tr>
<tr>
<td>Password</td>
<td><input type="text" name="txtpassword" id="txtpassword" /></td>
</tr>
<tr>
<th colspan="2"><div id="messageDiv" align="center"></div></th>
</tr>
<tr>
<th colspan="2"><input type="button" onclick="LoginVerify()" value="Login" name="btn1" /></th>
</tr>
</table>
</form>
</body>
</html>
