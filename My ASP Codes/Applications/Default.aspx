<%@ Page Language="C#" AutoEventWireup="true"  CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Untitled Page</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    <table border="2" cellpadding="5" cellspacing="0" width="400px" align="center">
    <tr>
    <th colspan="2">Application Example</th>
    </tr>
    <tr align="center">
    <td ><asp:TextBox ID="TextBox1" runat="server" ></asp:TextBox></td>
    <td ><asp:TextBox ID="TextBox2" runat="server" ></asp:TextBox></td>
    </tr>
    <tr align="center">
    <td><asp:Button ID="Button1" runat="server" Text="Store" 
            onclick="Button1_Click" /></td>
    <td><asp:Button ID="Button2" runat="server" Text="Retrieve" 
            onclick="Button2_Click" /></td>
    </tr>
    </table>
    </div>
    </form>
</body>
</html>
