<%@ Page Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="Search.aspx.cs" Inherits="Search" Title="Untitled Page" %>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
<br /><br /><br />

<table width="500px" border="1" cellpadding="5" cellspacing="0" align="center" >
<tr>
<th colspan="2"><u>SEARCH RECORD</u></th>
</tr>
<tr>
<td>ID</td>
<td><asp:TextBox ID="TextBox1" runat="server" ></asp:TextBox></td>
</tr>

<tr>
<th colspan="2">
    <asp:Label ID="Label1" runat="server"  Visible="false"></asp:Label>
</th>
</tr>
<tr>
<th colspan="2">
<asp:Table ID="Table1" runat="server" GridLines="Both" Width="500px" ></asp:Table>
</th>
</tr>
<tr>
<th colspan="2">
<asp:Button ID="searchBtn" runat="server" Text="Search" onclick="searchBtn_Click" 
          />&nbsp;&nbsp;

</th>
</tr>
</table>
<asp:AccessDataSource ID="AccessDataSource1" runat="server" 
        DataFile="~/App_Data/studentDatabase.mdb" DataSourceMode="DataReader" 
        SelectCommand="SELECT * FROM [student]"></asp:AccessDataSource>
</asp:Content>

