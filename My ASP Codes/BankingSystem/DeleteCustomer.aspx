<%@ Page Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="DeleteCustomer.aspx.cs" Inherits="DeleteCustomer" Title="Untitled Page" %>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
<br /><br /><br />
<table width="500px" cellspacing="0" cellpadding="10" border="1" align="center" >
<tr>
<th colspan="2" style="background-color:White; color:#6688ff;"><u><b>DELETE CUSTOMER</b></u></th>
</tr>
<tr>
<td>Customer ID</td>
<td><asp:TextBox ID="idTB" runat="server"></asp:TextBox></td>
</tr>
<tr>
<th colspan="2" align="left">
    <asp:Label ID="dataLB" runat="server" Visible="false"></asp:Label>

</th>
</tr>
<tr>
<th colspan="2" align="center">
    <asp:Label ID="Label1" runat="server" Visible="false"></asp:Label>
    </th>
</tr>
<tr>
<th colspan="2">
<asp:Button ID="showBTN" runat="server" Text="Show" onclick="showBTN_Click" />
<asp:Button ID="deleteBTN" runat="server" Text="Delete" onclick="deleteBTN_Click" />

</th>
</tr>
</table>
</asp:Content>

