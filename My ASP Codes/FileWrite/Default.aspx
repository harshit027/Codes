<%@ Page Language="C#" AutoEventWireup="true"  CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Untitled Page</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    <table width="300" border="1" cellpadding="5" cellspacing="0" align="center">
    <tr  >
    <th colspan="2" style="background-color:#dddddd;  color:#0000aa;">User Information</th>    
    </tr>
    <tr >
    <td>Name</td>
    <td><asp:TextBox ID="TextBox1" runat="server" Text=""></asp:TextBox></td>
    </tr>
    <tr >
    <td>Password</td>
    <td><asp:TextBox ID="TextBox2" runat="server" Text="" TextMode="Password"></asp:TextBox></td>
    </tr>
    <tr >
    <td>Email</td>
    <td><asp:TextBox ID="TextBox3" runat="server" Text=""></asp:TextBox></td>
    </tr>
    <tr align="center">
    <td colspan="2">
    <asp:Button ID="Button1" runat="server" Text="Submit" OnClick="submitClick" />
    &nbsp&nbsp&nbsp
    <asp:Button ID="Button2" runat="server" Text="Reset" OnClick="resetClick" />
    </td>
    </tr>
    </table>
    </div>
    </form>
</body>
</html>
