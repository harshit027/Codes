<%@ Page Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="NewTransaction.aspx.cs" Inherits="NewTransaction" Title="Untitled Page" %>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
<br /><br />
<table width="500px" cellspacing="0" cellpadding="10" border="1" align="center" >
<tr>
<th colspan="2" style="background-color:White; color:#6688ff;"><u><b>NEW TRANSACTION</b></u></th>
</tr>
<tr>
<td>Account No</td>
<td><asp:TextBox ID="accountNoTB" runat="server"></asp:TextBox></td>
</tr>

<tr>
<td>Amount</td>
<td><asp:TextBox ID="amountTB" runat="server"></asp:TextBox></td>
</tr>
<tr>
<td>Type</td>
<td>
<asp:DropDownList ID="transtypeDDL" runat="server">
<asp:ListItem Text="Deposit" Value="D"></asp:ListItem>
<asp:ListItem Text="Withdraw" Value="W"></asp:ListItem>
</asp:DropDownList>
</td>
</tr>

<tr>
<th colspan="2" align="center">
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

