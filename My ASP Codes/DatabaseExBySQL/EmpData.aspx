<%@ Page Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="EmpData.aspx.cs" Inherits="EmpData" Title="Untitled Page" %>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
<br /><br />
<table width="500px" border="1" cellpadding="5" cellspacing="0" align="center">
<tr>
<td style="background-color:White;"><u><b>EMPLOYEE DATABASE</b></u></td>
</tr>
<tr>
<td>
<asp:Table ID="Table1" runat="server" GridLines="Both" Width="500px"></asp:Table>
</td>
</tr>
<tr>
<th><asp:Button ID="Button1" runat="server" Text="Show Data" 
        onclick="Button1_Click" />
    <asp:SqlDataSource ID="SqlDataSource2" runat="server" DataSourceMode="DataReader"
        ConnectionString="<%$ ConnectionStrings:ConnectionString %>" 
        SelectCommand="SELECT * FROM [employee]"></asp:SqlDataSource>
    </th>
</tr>
</table>
</asp:Content>

