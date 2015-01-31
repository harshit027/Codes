<%@ Page Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="StaffHome.aspx.cs" Inherits="StaffHome" Title="Untitled Page" %>


<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">

<table cellpadding="2" cellspacing="2" width="100%"; border="0">
<tr>
<td><img src="images/flower.jpg" alt="Hello" height="420px" width="500px" />  </td>
<td>
<table width="400px" border="2" style="background-color:#dddddd; vertical-align:top; " align="center" cellspacing="0" cellpadding="5">
<tr>
<th colspan="2" ><u><b>LOGGED IN AS</b></u></th>
</tr>
<tr>
<td>Login Id</td>
<td><asp:Label ID="idLB" runat="server" Text=""></asp:Label></td>
</tr>
<tr>
<td>Name</td>
<td><asp:Label ID="nameLB" runat="server" Text=""></asp:Label></td>
</tr>
<tr>
<td>Phone No</td>
<td><asp:Label ID="phoneLB" runat="server" Text=""></asp:Label></td>
</tr>
<tr>
<td>Email Id</td>
<td><asp:Label ID="emailLB" runat="server" Text=""></asp:Label></td>
</tr>

</table>
</td>
</tr>
</table>
</asp:Content>

