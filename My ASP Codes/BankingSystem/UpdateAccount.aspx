<%@ Page Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="UpdateAccount.aspx.cs" Inherits="UpdateAccount" Title="Untitled Page" %>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
<br /><br />
<table width="500px" cellspacing="0" cellpadding="10" border="1" align="center" >
<tr>
<th colspan="2" style="background-color:White; color:#6688ff;"><u><b>UPDATE ACCOUNT</b></u></th>
</tr>
<tr>
<td>Account No</td>
<td><asp:TextBox ID="accountNoTB" runat="server"></asp:TextBox></td>
</tr>

<tr>
<td>Account Type</td>
<td><asp:DropDownList ID="acctypeDDL" runat="server" >
<asp:ListItem Text="Saving" Value="S"></asp:ListItem>
<asp:ListItem Text="Current" Value="C"></asp:ListItem>
</asp:DropDownList></td>
</tr>

<tr>
<th colspan="2" align="left">
    <asp:Label ID="Label1" runat="server" Visible="false"></asp:Label>
</th>
</tr>
<tr>
<th colspan="2">
<asp:Button ID="showBTN" runat="server" Text="Show" onclick="showBTN_Click"/>
<asp:Button ID="submitBTN" runat="server" Text="Submit" onclick="submitBTN_Click" />
</th>
</tr>
</table>
</asp:Content>

