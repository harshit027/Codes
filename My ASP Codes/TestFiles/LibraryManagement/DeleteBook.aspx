<%@ Page Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="DeleteBook.aspx.cs" Inherits="DeleteBook" Title="Untitled Page" %>


<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
    <br /><br /><br />

<table width="400px" align="center" border="1" cellpadding="5" cellspacing="0">
<tr>
<th colspan="2"><u><b>DELETE BOOK</b></u></th>
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
    <asp:Label ID="Label1" runat="server" Text="Label" Visible="false"></asp:Label>
</th>
</tr>
<tr>
<th colspan="2">
<asp:Button ID="Button1" runat="server" Text="Delete" onclick="Button1_Click" />
</th>
</tr>
</table>
</asp:Content>

