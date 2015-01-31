<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default2.aspx.cs" Inherits="Default2" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Untitled Page</title>
</head>
<body>
    <form id="form1" runat="server">
    <center>
    <div>
    <table border="1" cellspacing="0" width="300px">
    <tr align="center">
    <td>Color 1</td>
    <td><asp:TextBox ID="TextBox1" runat="server" Text=""></asp:TextBox></td>
    </tr>
    <tr align="center">
    <td>Color 2</td>
    <td><asp:TextBox ID="TextBox2" runat="server" Text=""></asp:TextBox></td>
    </tr>
    <tr align="center">
    <td colspan=2><asp:Button ID="Button1" runat="server" Text="RetrieveCookie" OnClick="RetrieveCookie" /></td>
    </tr>
    </table>
    </div>
    </center>
    </form>
</body>
</html>
