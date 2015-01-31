<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Untitled Page</title>
</head>
<body>
    <form id="form1" runat="server">
    <div style="text-align: center">
        <table cellpadding="2" border="1">
            <tr>
                <td>
                    <asp:Button ID="btn5" runat="server" Text="UP" onclick="btn5_Click" />
                </td>
                <td style="text-align: center">
                    <asp:ListBox ID="lst1" runat="server" SelectionMode="Multiple" Height="207px" 
                        Width="169px">
                        <asp:ListItem Selected="True" Text="Red" Value="red"></asp:ListItem>
                        <asp:ListItem Text="Green" Value="green"></asp:ListItem>
                        <asp:ListItem Selected="True" Text="Blue" Value="blue"></asp:ListItem>
                    </asp:ListBox>
                </td>
                <td>
                    <asp:Button ID="btn1" runat="server" Text=">" onclick="btn1_Click" /><br />
                    <asp:Button ID="Button1" runat="server" Text="<" onclick="btn1_Click" /><br />
                    <asp:Button ID="Button2" runat="server" Text=">>" onclick="btn1_Click" /><br />
                    <asp:Button ID="Button3" runat="server" Text="<<" onclick="btn1_Click" /><br />
                </td>
                <td>
                    <asp:ListBox ID="ListBox1" runat="server" SelectionMode="Multiple" Height="207px" 
                        Width="169px">
                        <asp:ListItem Selected="True" Text="Red" Value="red"></asp:ListItem>
                    </asp:ListBox>
                </td>
            </tr>
        </table>
    </div>
    </form>
</body>
</html>
