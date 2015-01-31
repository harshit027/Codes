<%@ Page Language="C#" AutoEventWireup="true"  CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Untitled Page</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <table border="1">
            <tr>
                <td colspan="4"><asp:Literal ID="Literal1" runat="server" Text="0"/></td>
            </tr>
            <tr>
                <td><asp:Button ID="btn1" runat="server" Text="7" OnClick = "Calculate" /></td>
                <td><asp:Button ID="btn2" runat="server" Text="8" OnClick = "Calculate" /></td>
                <td><asp:Button ID="btn3" runat="server" Text="9" OnClick = "Calculate" /></td>
                <td><asp:Button ID="btn4" runat="server" Text="/" OnClick = "Calculate" /></td>
            </tr>
            <tr>
                <td><asp:Button ID="Button1" runat="server" Text="4" OnClick = "Calculate" /></td>
                <td><asp:Button ID="Button2" runat="server" Text="5" OnClick = "Calculate" /></td>
                <td><asp:Button ID="Button3" runat="server" Text="6" OnClick = "Calculate" /></td>
                <td><asp:Button ID="Button4" runat="server" Text="*" OnClick = "Calculate" /></td>
            </tr>
            <tr>
                <td><asp:Button ID="Button5" runat="server" Text="1" OnClick = "Calculate" /></td>
                <td><asp:Button ID="Button6" runat="server" Text="2" OnClick = "Calculate" /></td>
                <td><asp:Button ID="Button7" runat="server" Text="3" OnClick = "Calculate" /></td>
                <td><asp:Button ID="Button8" runat="server" Text="-" OnClick = "Calculate" /></td>
            </tr>
            <tr>
                <td><asp:Button ID="Button9" runat="server" Text="0" OnClick = "Calculate" /></td>
                <td><asp:Button ID="Button10" runat="server" Text="." OnClick = "Calculate" /></td>
                <td><asp:Button ID="Button11" runat="server" Text="=" OnClick = "Calculate" /></td>
                <td><asp:Button ID="Button12" runat="server" Text="+" OnClick = "Calculate" /></td>
            </tr>
        </table>
        <asp:Literal ID="Literal2" runat="server" Text=  "" Visible=false></asp:Literal>
        <asp:Literal ID="Literal3" runat="server" Text=  "" Visible=false></asp:Literal>
    </div>
    </form>
</body>
</html>
