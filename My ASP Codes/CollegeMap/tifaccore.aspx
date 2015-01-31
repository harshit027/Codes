<%@ Page Language="C#" AutoEventWireup="true" CodeFile="tifaccore.aspx.cs" Inherits="tifaccore" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Untitled Page</title>
    <style type="text/css">
        .style1
        {
            height: 424px;
            width: 578px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
    <div align=left>
    <asp:Image ID="headerimage" runat="server" ImageUrl="~/images/header.jpg" />
    </div><br />
    <h1><u>High Voltage Lab</u></h1><br /><br />
    <div>
    <table align=center border=2>
    <tr>
    <td class="style1">
        <asp:Image ID="csit1" runat="server" 
            ImageUrl="~/images/tifaccore.JPG" Height="421px" Width="590px" /></td>
    </tr>
    </table>
    
    </div>
    <div>
    <asp:HyperLink ID="home" runat="server" Text="Home" NavigateUrl="~/Default.aspx"></asp:HyperLink>
    </div>
    </form>
</body>
</html>
