<%@ Page Language="C#" AutoEventWireup="true"  CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Untitled Page</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    <table width="500px" border="1" cellpadding="4" cellspacing="0" align="center">
    <tr>
    <td>Name</td>
    <td><asp:TextBox ID="TextBox1" runat="server"></asp:TextBox></td>
    </tr>
    <tr>
    <td>College</td>
    <td><asp:TextBox ID="TextBox2" runat="server"></asp:TextBox></td>
    </tr>
    <tr>
    <td>Branch</td>
    <td><asp:TextBox ID="TextBox3" runat="server"></asp:TextBox></td>
    </tr>
    <tr align="center">
    <td colspan="2">
    <asp:Button ID="first" runat="server" Text="First" onclick="first_Click1" />&nbsp;
    <asp:Button ID="next" runat="server" Text="Next" onclick="next_Click" />&nbsp;
    <asp:Button ID="previous" runat="server" Text="Previous" onclick="previous_Click" />&nbsp;
    <asp:Button ID="last" runat="server" Text="Last" onclick="last_Click" />&nbsp;
    
        <asp:SqlDataSource ID="SqlDataSource1" runat="server" DataSourceMode="DataSet"
            ConnectionString="<%$ ConnectionStrings:ConnectionString %>" 
            SelectCommand="SELECT * FROM [student]"></asp:SqlDataSource>
    
    </td>
    </tr>
    </table>
    </div>
    </form>
</body>
</html>
