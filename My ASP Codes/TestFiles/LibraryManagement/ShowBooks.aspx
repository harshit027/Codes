<%@ Page Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="ShowBooks.aspx.cs" Inherits="ShowBooks" Title="Untitled Page" %>


<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
    <br /><br />
<table width="600px" border="1" cellpadding="5" cellspacing="0" align="center">
<tr>
<th><u>BOOK LIST</u></th>
</tr>
<tr>
<td><asp:Table ID="Table1" runat="server" GridLines="Both" Width="600px">

</asp:Table></td>
</tr>
<tr>
<th>
<asp:Button ID="Button1" runat="server" Text="Show Books" onclick="Button1_Click" Visible="true"/>
</th>
</tr>
</table>
</asp:Content>

