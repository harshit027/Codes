<%@ Page Language="C#" AutoEventWireup="true" MasterPageFile="~/MasterPage.master" CodeFile="DeptData.aspx.cs" Inherits="DeptData" %>

<asp:Content ContentPlaceHolderID="ContentPlaceHolder1" ID="Content1" runat="server">
    <br /><br />
<table width="500px" border="1" cellpadding="5" cellspacing="0" align="center">
<tr>
<td style="background-color:White;"><u><b>DEPARTMENT DATABASE</b></u></td>
</tr>
<tr>
<td>
<asp:Table ID="Table1" runat="server" GridLines="Both" Width="500px"></asp:Table>
</td>
</tr>
<tr>
<th><asp:Button ID="Button1" runat="server" Text="Show Data" 
        onclick="Button1_Click" />
    <asp:SqlDataSource ID="SqlDataSource1" runat="server" DataSourceMode="DataReader"
        ConnectionString="<%$ ConnectionStrings:ConnectionString %>" 
        SelectCommand="SELECT * FROM [department]"></asp:SqlDataSource>
    </th>
</tr>
</table>
</asp:Content>

