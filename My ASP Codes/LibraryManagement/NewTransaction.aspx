<%@ Page Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="NewTransaction.aspx.cs" Inherits="NewTransaction" Title="Untitled Page" %>


<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
<br /><br />
<table width="500px" border="1" cellpadding="2" cellspacing="0" align="center">
<tr>
<th colspan="2"><b><u>NEW TRANSACTION</u></b></th>
</tr>
<tr>
<td>BookID</td>
<td><asp:TextBox ID="bookidTB" runat="server" Text=""></asp:TextBox></td>
</tr>
<tr>
<td>MemberID</td>
<td><asp:TextBox ID="memberidTB" runat="server" Text=""></asp:TextBox></td>
</tr>
<tr>
<td>Date</td>
<td><asp:TextBox ID="dateTB" runat="server" Text="MM/DD/YYYY"></asp:TextBox></td>
</tr>

<tr>
<td>Type</td>
<td><asp:DropDownList ID="type_of_transLT" runat="server">
<asp:ListItem Text="Issue" Value="I"></asp:ListItem>
<asp:ListItem Text="Return" Value="R"></asp:ListItem>
</asp:DropDownList>
</td>
</tr>
<tr align="center">
<th colspan="2">
    <asp:Label ID="Label1" runat="server" Text="Label" Visible="false"></asp:Label>
</th>
</tr>
<tr>
<th colspan="2">
<asp:Button ID="okBTN" runat="server" Text="Ok" onclick="okBTN_Click"/>
<asp:Button ID="cancelBTN" runat="server" Text="Cancel" onclick="cancelBTN_Click"/>
</th>
</tr>
</table>
</asp:Content>

