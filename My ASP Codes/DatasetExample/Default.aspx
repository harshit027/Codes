﻿<%@ Page Language="C#" AutoEventWireup="true"  CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Untitled Page</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    <table width="500px" border="1" cellspacing="0" align="center">
    <tr align="center">
    <td>
    <asp:Table ID="Table1" runat="server" Width="500px" GridLines="Both" ></asp:Table>
    </td>
    </tr>
    <tr align="center">
    <td><asp:Button ID="Button1" runat="server" Text="Show Data" 
            onclick="Button1_Click" />
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
