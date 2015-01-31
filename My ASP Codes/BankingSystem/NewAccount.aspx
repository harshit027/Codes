<%@ Page Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="NewAccount.aspx.cs" Inherits="NewAccount" Title="Untitled Page" %>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
<br /><br />
<table width="500px" cellspacing="0" cellpadding="10" border="1" align="center" >
<tr>
<th colspan="2" style="background-color:White; color:#6688ff;"><u><b>NEW ACCOUNT</b></u></th>
</tr>
<tr>
<td>Customer ID</td>
<td><asp:TextBox ID="idTB" runat="server"></asp:TextBox></td>
</tr>
<tr>
<td>Account Type</td>
<td><asp:DropDownList ID="acctypeDDL" runat="server" >
<asp:ListItem Text="Saving" Value="S"></asp:ListItem>
<asp:ListItem Text="Current" Value="C"></asp:ListItem>
</asp:DropDownList></td>
</tr>
<tr>
<td>Current Balance</td>
<td><asp:TextBox ID="currentbalTB" runat="server"></asp:TextBox></td>
</tr>
<tr>
<th colspan="2">
    <asp:Label ID="Label1" runat="server" Visible="false"></asp:Label>
</th>
</tr>
<tr>
<th colspan="2">
<asp:Button ID="submitBTN" runat="server" Text="Submit" onclick="submitBTN_Click" />

<asp:Button ID="resetBTN" runat="server" Text="Reset" onclick="resetBTN_Click" />
</th>
</tr>
</table>
</asp:Content>

