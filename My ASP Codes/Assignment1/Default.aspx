<%@ Page Language="C#" AutoEventWireup="true"  CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Untitled Page</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    <asp:DropDownList ID="ddlCountries" runat="server" AutoPostBack="True" 
            onselectedindexchanged="ddl1_SelectedIndexChanged" >
    <asp:ListItem Text="------------" Value="blank"></asp:ListItem>        
    <asp:ListItem Text="India" Value="India"></asp:ListItem>
    <asp:ListItem Text="Pakistan" Value="Pakistan"></asp:ListItem>
    <asp:ListItem Text="China" Value="China"></asp:ListItem>
    <asp:ListItem Text="Russia" Value="Russia"></asp:ListItem>
    </asp:DropDownList>
    <br /><br />
    <asp:DropDownList ID="ddlStates" runat="server" AutoPostBack="True" >
    </asp:DropDownList>
    </div>
    </form>
</body>
</html>
