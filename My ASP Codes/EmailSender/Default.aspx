<%@ Page Language="C#" AutoEventWireup="true"  CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Untitled Page</title>
    <style type="text/css">
        .style1 {
            width: 102px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    <table width="100%" border="1" cellspacing="0" cellpadding="4">
    <tr>
    <td class="style1">To</td>
    <td><asp:TextBox ID="TextBox1" runat="server" Width="788px"></asp:TextBox></td>
    </tr>
    <tr>
    <td class="style1">From</td>
    <td><asp:TextBox ID="TextBox2" runat="server" Width="786px"></asp:TextBox></td>
    </tr>
    <tr>
    <td class="style1">Subject</td>
    <td><asp:TextBox ID="TextBox3" runat="server" Width="783px"></asp:TextBox></td>
    </tr>
    <tr >
    <td valign="top" class="style1">Message</td>
    <td><asp:TextBox ID="TextBox4"  TextMode="MultiLine" Rows="10" runat="server" 
            Width="783px"></asp:TextBox></td>
    </tr>
    <tr>
    <td class="style1" colspan="2">
    <asp:Button ID="Button1" runat="server" Text="Send" onclick="Button1_Click" />&nbsp;
    <asp:Button ID="Button2" runat="server" Text="Clear" />
    </td>
    </tr>
    </table>
    </div>
    </form>
</body>
</html>
