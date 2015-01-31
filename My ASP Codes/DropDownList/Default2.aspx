<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default2.aspx.cs" Inherits="Default2" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Untitled Page</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <asp:DropDownList ID="ddlColor" runat="server">
            <asp:ListItem Text="Red" Value="#ff0000"></asp:ListItem>
            <asp:ListItem Text="Green" Value="#00ff00"></asp:ListItem>
            <asp:ListItem Text="Blue" Value="#0000ff"></asp:ListItem>
            <asp:ListItem Text="Yellow" Value="#ffff00"></asp:ListItem>
            <asp:ListItem Text="Cyan" Value="#00ffff"></asp:ListItem>
        </asp:DropDownList>
        <br />
        <asp:TextBox runat="server" ID="txt1" Text="PACE BUREAU"></asp:TextBox>
        <br />
        <asp:Button runat="server" ID="btn1" Text="Change Color" onclick="btn1_Click" />
        <asp:DropDownList ID="DropDownList1" runat="server" AutoPostBack="True" 
            onselectedindexchanged="DropDownList1_SelectedIndexChanged">
            <asp:ListItem>red</asp:ListItem>
            <asp:ListItem>green</asp:ListItem>
            <asp:ListItem>blue</asp:ListItem>
            <asp:ListItem>yellow</asp:ListItem>
            <asp:ListItem>cyan</asp:ListItem>
            <asp:ListItem Selected="True">magenta</asp:ListItem>
            <asp:ListItem>black</asp:ListItem>
            <asp:ListItem>white</asp:ListItem>
            <asp:ListItem>orange</asp:ListItem>
            <asp:ListItem>pink</asp:ListItem>
            <asp:ListItem>gray</asp:ListItem>
        </asp:DropDownList>
        <br />
        <asp:DropDownList ID="ddlnew" runat="server">
            
        </asp:DropDownList>
        <br />
        <asp:Button ID="Button1" runat="server" onclick="Button1_Click" Text="Button" />
    </div>
    </form>
</body>
</html>
