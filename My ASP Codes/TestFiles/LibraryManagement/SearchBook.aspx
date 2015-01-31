<%@ Page Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="SearchBook.aspx.cs" Inherits="SearchBook" Title="Untitled Page" %>


<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
    <br /><br /><br />

<table width="500px" align="center" border="1" cellpadding="5" cellspacing="0">
<tr>
<th colspan="2"><u><b>SEARCH BOOK</b></u></th>
</tr>
<tr>
<td>
Book ID
</td>
<td>
<asp:TextBox ID="TextBox1" runat="server" Text=""></asp:TextBox>
</td>
</tr>

<tr align="center">
<th colspan="2">
    <asp:Table ID="Table1" runat="server" Width="500px" GridLines="Both">
    </asp:Table>
</th>
</tr>
<tr>
<th colspan="2">
<asp:Button ID="Button1" runat="server" Text="Search" onclick="Button1_Click" />
</th>
</tr>
</table>
</asp:Content>

