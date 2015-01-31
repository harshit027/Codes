<%@ Page Language="C#" AutoEventWireup="true"  CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Untitled Page</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    <table width="400px" border="2" cellpadding="5" cellspacing="0" align="center">
    <tr>
    <th colspan="2">LOGIN</th>
    </tr>
    <tr>
    <td>Username</td>
    <td><asp:TextBox ID="TextBox1" runat="server" ></asp:TextBox></td>
    </tr>
    <tr>
    <td>Password</td>
    <td><asp:TextBox ID="TextBox2" runat="server" TextMode="Password" ></asp:TextBox></td>
    </tr>
    <tr align="center">
    <td colspan="2"><asp:Literal ID="Literal1" runat="server" Text="" Visible="false"></asp:Literal></td>
    </tr>
    <tr>
    <th colspan="2"><asp:Button ID="Login" runat="server" Text="Login" 
            onclick="Login_Click" /></th>
    </tr>
    </table>
    </div>
    </form>
</body>
</html>
