<%@ Page Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="EmpEntry.aspx.cs" Inherits="EmpEntry" Title="Untitled Page" %>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">

<br /><br />
<table width="500px" border="1" cellpadding="5" cellspacing="0" align="center">
<tr>
<th colspan="2"><u>NEW DEPARTMENT</u></th>
</tr>
<tr align="left">
<td >Name</td>
<td><asp:TextBox ID="TextBox1" runat="server" ></asp:TextBox></td>
</tr>
<tr align="left">
<td>Qualification</td>
<td><asp:DropDownList ID="List1" runat="server">
<asp:ListItem Text="UnderGraduate"></asp:ListItem>
<asp:ListItem Text="Graduate"></asp:ListItem>
<asp:ListItem Text="PostGraduate"></asp:ListItem>
</asp:DropDownList> </td>
</tr>
<tr align="left">
<td>Salary</td>
<td><asp:TextBox ID="TextBox3" runat="server" ></asp:TextBox></td>
</tr>
<tr align="left">
<td>Department No.</td>
<td><asp:TextBox ID="TextBox4" runat="server" ></asp:TextBox></td>
</tr>
<tr>
<th colspan="2">
    <asp:Label ID="Label1" runat="server"  Visible="false"></asp:Label>
</th>
</tr>
<tr>
<th colspan="2">
<asp:Button ID="save" runat="server" Text="Save" onclick="save_Click" />&nbsp;&nbsp;
<asp:Button ID="reset" runat="server" Text="Reset" onclick="reset_Click" />
    <asp:SqlDataSource ID="SqlDataSource1" runat="server" DataSourceMode="DataReader"
        ConnectionString="<%$ ConnectionStrings:ConnectionString %>" 
        SelectCommand="SELECT * FROM [employee]"></asp:SqlDataSource>
</th>
</tr>
</table>
</asp:Content>

