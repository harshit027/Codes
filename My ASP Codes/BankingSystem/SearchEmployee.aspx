<%@ Page Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="SearchEmployee.aspx.cs" Inherits="SearchEmployee" Title="Untitled Page" %>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">

<table width="500px" cellspacing="0" cellpadding="10" border="1" align="center" >
<tr>
<th colspan="2" style="background-color:White; color:#6688ff;"><u><b>SEARCH EMPLOYEE</b></u></th>
</tr>
<tr>
<td>Employee ID</td>
<td><asp:TextBox ID="idTB" runat="server"></asp:TextBox></td>
</tr>
<tr>
<td>Name</td>
<td><asp:TextBox ID="nameTB" runat="server" ReadOnly="true"></asp:TextBox></td>
</tr>
<tr>
<td>Phone</td>
<td><asp:TextBox ID="phoneTB" runat="server" ReadOnly="true"></asp:TextBox></td>
</tr><tr>
<td>Email Id</td>
<td><asp:TextBox ID="emailTB" runat="server" ReadOnly="true"></asp:TextBox></td>
</tr><tr>
<td>Address</td>
<td><asp:TextBox ID="addressTB" runat="server" TextMode="MultiLine" Rows="3" Columns="25" ReadOnly="true"></asp:TextBox></td>
</tr>
<tr>
<th colspan="2" style="text-align:center;">
    <asp:Label ID="Label1" runat="server" Visible="false"></asp:Label>
</th>
</tr>
<tr>
<th colspan="2">
<asp:Button ID="searchBTN" runat="server" Text="Search" onclick="searchBTN_Click" />
<asp:Button ID="cancelBTN" runat="server" Text="Cancel" onclick="cancelBTN_Click" />
</th>
</tr>
</table>
</asp:Content>

