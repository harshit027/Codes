<%@ Page Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="NewEmployee.aspx.cs" Inherits="NewEmployee" Title="Untitled Page" %>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
<br /><br />
<table width="500px" cellspacing="0" cellpadding="6" border="1" align="center" >
<tr>
<th colspan="2" style="background-color:White; color:#6688ff;"><u><b>NEW EMPLOYEE</b></u></th>
</tr>
<tr>
<td>Name</td>
<td><asp:TextBox ID="nameTB" runat="server"></asp:TextBox></td>
</tr>
<tr>
<td>Password</td>
<td><asp:TextBox ID="passwordTB" runat="server"></asp:TextBox></td>
</tr>
<tr>
<td>Phone</td>
<td><asp:TextBox ID="phoneTB" runat="server"></asp:TextBox></td>
</tr>
<tr>
<td>Email Address</td>
<td><asp:TextBox ID="emailTB" runat="server"></asp:TextBox></td>
</tr>
<tr>
<td>Address</td>
<td><asp:TextBox ID="addressTB" runat="server" TextMode="MultiLine" Rows="3" Columns="30"></asp:TextBox></td>
</tr>
<tr>
<th colspan="2" style="text-align:center;">
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

