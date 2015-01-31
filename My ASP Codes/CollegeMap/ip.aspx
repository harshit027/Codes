<%@ Page Language="C#" AutoEventWireup="true" CodeFile="ip.aspx.cs" Inherits="ip" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Untitled Page</title>
</head>
<body>
    <form id="form1" runat="server">
    <div align=left>
    <asp:Image ID="headerimage" runat="server" ImageUrl="~/images/header.jpg" />
    </div><br />
    <h1><u>Industrial Production Department</u></h1><br /><br />
    <div>
    <table align=center border=2>
    <tr>
    <td><asp:Image ID="ip1" runat="server" ImageUrl="~/images/ip.jpg" Height="415px" 
            style="margin-bottom: 0px" Width="606px" /></td>
    </tr>
    </table>
    
    </div>
    <div>
    <asp:HyperLink ID="home" runat="server" Text="Home" NavigateUrl="~/Default.aspx"></asp:HyperLink>
    </div>
    </form>
</body>
</html>
