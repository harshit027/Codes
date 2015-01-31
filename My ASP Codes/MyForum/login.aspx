<%@ Page Language="C#" MasterPageFile="~/Master1.master" AutoEventWireup="true" CodeFile="login.aspx.cs" Inherits="login" Title="Untitled Page" %>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
<div style="background-color:#0077ff; height:495px;">
<br /><br />
<table width="300px" align="center" style="height:220px; color:white;">
<tr style="background-color:White; color:#0077ff;">
<th colspan="2"><u>USER</u></th>
</tr>
<tr>
<td>Username</td>
<td><asp:TextBox ID="TextBox1" runat="server" Text=""></asp:TextBox></td>
</tr>
<tr>
<td>Password</td>
<td><asp:TextBox ID="TextBox2" runat="server" ></asp:TextBox></td>
</tr>
<tr align="center">
<td colspan="2">
<asp:Button ID="Button1" runat="server" Text="Login" />
</td>
</tr>
</table>
</div>
</asp:Content>

