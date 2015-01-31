<%@ Page Language="C#" AutoEventWireup="true"  CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Untitled Page</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    <table border="1" width="100%">
    <tr>
    <td>
    <asp:Menu ID="Menu1" runat="server" Orientation="Horizontal">
    <Items>
    <asp:MenuItem Text="Home" NavigateUrl="~/Default.aspx"></asp:MenuItem>
    <asp:MenuItem Text="Student" NavigateUrl="~/Student.aspx">
    <asp:MenuItem Text="New" NavigateUrl="~/New.aspx"></asp:MenuItem>
    <asp:MenuItem Text="Delete" NavigateUrl="~/Delete.aspx"></asp:MenuItem>
    </asp:MenuItem>
    <asp:MenuItem Text="Teachers" NavigateUrl="~/Teachers.aspx">
        <asp:MenuItem Text="New" NavigateUrl="~/New.aspx"></asp:MenuItem>
    <asp:MenuItem Text="Delete" NavigateUrl="~/Delete.aspx"></asp:MenuItem>
    </asp:MenuItem>
    <asp:MenuItem Text="Staff" NavigateUrl="~/Staff.aspx">
        <asp:MenuItem Text="New" NavigateUrl="~/NewMember.aspx"></asp:MenuItem>
    <asp:MenuItem Text="Delete" NavigateUrl="~/DeleteMember.aspx"></asp:MenuItem>
    </asp:MenuItem>
    </Items>
    </asp:Menu>
    </td>
    </tr>
    </table>
    </div>
    </form>
</body>
</html>
