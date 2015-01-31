<%@ Page Language="C#" AutoEventWireup="true"  CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Untitled Page</title>
    <script type='text/javascript' src='location properties.js'>
    </script>
</head>
<body>
    <form id="form1" runat="server">
    <table border='1' cellpadding='5' cellspacing='0' align='center' width='500' style='background-color:#dddddd; font-family:Verdana; font-size:5;'>
<tr align='center' style='background-color:purple; color:white;'>
<td colspan='2'>Location Properties</td>
</tr>
<tr>
<td>Anchor</td>
<td><input type='button' ID='btn1' name='btn1' value='Anchor' onclick='showAnchor();' /></td>
</tr>
<tr>
<td>Host Name</td>
<td><input type='button' ID='btn2' name='btn2' value='Hostname' onclick='showHost();' /></td>
</tr>
<tr>
<td>Pathname</td>
<td><input type='button' ID='btn3' name='btn3' value='Pathname' onclick='showPath();' /></td>
</tr>
<tr>
<td>Port Number</td>
<td><input type='button' ID='btn4' name='btn4' value='Port No.' onclick='showPort();' /></td>
</tr>
<tr>
<td>Protocol</td>
<td><input type='button' ID='btn5' name='btn5' value='Protocol' onclick='showProtocol();' /></td>
</tr>
<tr>
<td>URL</td>
<td><input type='button' ID='btn6' name='btn6' value='URL' onclick='showURL();' /></td>
</tr>
</table>
    </form>
</body>
</html>
