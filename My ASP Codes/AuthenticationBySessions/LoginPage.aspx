<%@ Page Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="LoginPage.aspx.cs" Inherits="LoginPage" Title="Untitled Page" %>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">

<br /><br />

<table width="500px" align="center" cellpadding="5" cellspacing="0" border="1">
<tr>
<th colspan="2"><u>LOGIN</u></th>
</tr>
<tr>
<td>Username : </td>
<td><asp:TextBox ID="TextBox1" runat="server"></asp:TextBox></td>
</tr>

<tr>
<td>Password : </td>
<td><asp:TextBox ID="TextBox2" runat="server" TextMode="Password"></asp:TextBox></td>
</tr>

<tr align="center" >
<td colspan="2">
<asp:Literal ID="Literal1" runat="server" Text="" Visible="false">
</asp:Literal>
</td>
</tr>
<tr>
<th colspan="2"><asp:Button ID="Login" runat="server" Text="Login" 
        onclick="Login_Click" style="height: 26px" /></th>
</tr>
</table>
</asp:Content>

