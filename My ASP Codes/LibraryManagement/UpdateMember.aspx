<%@ Page Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="UpdateMember.aspx.cs" Inherits="UpdateMember" Title="Untitled Page" %>


<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
<br /><br /><br />
<table width="500px" cellpadding="5" cellspacing="0" border="1" align="center">
<tr>
<th colspan="2"><b><u>UPDATE MEMBER</u></b></th>
</tr>
<tr align="left">
<td>Member ID</td>
<td><asp:TextBox ID="midTB" runat="server" Text="" AutoPostBack="true" 
        ontextchanged="midTB_TextChanged"></asp:TextBox></td>
</tr>
<tr align="left">
<td>Name</td>
<td><asp:TextBox ID="nameTB" runat="server" Text=""></asp:TextBox></td>
</tr>
<tr align="left">
<td>Address</td>
<td><asp:TextBox ID="addressTB" runat="server" Text=""></asp:TextBox></td>
</tr>
<tr align="left">
<td>Phone No</td>
<td><asp:TextBox ID="phoneTB" runat="server" Text=""></asp:TextBox></td>
</tr>
<tr align="left">
<td>Mobile No</td>
<td><asp:TextBox ID="mobileTB" runat="server" Text=""></asp:TextBox></td>
</tr>
<tr align="left">
<td>Email ID</td>
<td><asp:TextBox ID="emailTB" runat="server" Text=""></asp:TextBox></td>
</tr>

<tr align="center">
<th colspan="2">
    <asp:Label ID="Label1" runat="server" Text="Label" Visible="false"></asp:Label>
    </th>
</tr>

<tr>
<th colspan="2"><asp:Button ID="Button1" runat="server" Text="Update" 
        onclick="Button1_Click" />&nbsp;&nbsp;
<asp:Button ID="Button2" runat="server" Text="Cancel" onclick="Button2_Click" /></th>
</tr>
</table>
</asp:Content>

