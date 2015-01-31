<%@ Page Language="C#" AutoEventWireup="true"  MasterPageFile="~/MasterPage.master" CodeFile="Default.aspx.cs" Inherits="_Default" %>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
<h2>Default.aspx</h2>
<table width="300px" align="center">
<tr>
<td><asp:TextBox ID="TextBox1" runat="server"></asp:TextBox></td>
<td><asp:Button ID="Button1" runat="server" Text="PutOnSession" 
        onclick="Button1_Click" /></td>
</tr>
</table>
</asp:Content>