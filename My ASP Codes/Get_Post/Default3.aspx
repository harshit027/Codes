<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default3.aspx.cs" Inherits="Default3" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Untitled Page</title>
</head>
<body>
    <form id="form1" runat="server" method="post">
    <div>
        <table align="center" style="width:100%;">
            <tr>
                <td style="text-align: center">
                    &nbsp;</td>
            </tr>
            <tr>
                <td style="text-align: center">
                    <asp:TextBox ID="tb1" runat="server" Text=""></asp:TextBox><br />
                    <asp:TextBox ID="TextBox1" runat="server" Text=""></asp:TextBox><br />
                    <asp:TextBox ID="TextBox2" runat="server" Text=""></asp:TextBox><br />
                    <asp:Button ID="btn1" runat="server" Text="Send Data To Next Page" 
                        onclick="btn1_Click" />
                    
                </td>
            </tr>
            <tr>
                <td style="text-align: center">
                    &nbsp;</td>
            </tr>
        </table>
    </div>
    </form>
</body>
</html>
