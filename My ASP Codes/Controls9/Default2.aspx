<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default2.aspx.cs" Inherits="Default2" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Pace Bureau</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <asp:RadioButtonList ID="rb1" runat="server" AutoPostBack="true" 
            onselectedindexchanged="rb1_SelectedIndexChanged">
            <asp:ListItem Text="yellow"></asp:ListItem>
            <asp:ListItem Text="magenta"></asp:ListItem>
        </asp:RadioButtonList>
        <asp:HiddenField ID="hdn1" runat="server" Value="" />
        <br />
        <asp:Button ID="btn1" runat="server" Text="Show Theme" OnClick="ChangeTheme" />
    </div>
    </form>
</body>
</html>
