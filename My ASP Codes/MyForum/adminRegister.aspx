<%@ Page Language="C#" MasterPageFile="~/Master1.master" AutoEventWireup="true" CodeFile="adminRegister.aspx.cs" Inherits="adminRegister" Title="Untitled Page" %>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
<div style="background-color:#0077ff; height:495px;"><br />

<table cellspacing="0"  width="400px" align="center" style="height:250px; color:White;">
<tr style="background-color:White; color:#0077ff;">
<th colspan=2><u>ADMINISTRATOR</u></th>
</tr>

<tr>
<td>Name</td>
<td><asp:TextBox ID="nameTB" runat="server" ></asp:TextBox></td>
</tr>

<tr>
<td>Password</td>
<td><asp:TextBox ID="passwordTB" runat="server" ></asp:TextBox></td>
</tr>

<tr>
<td>Retype Password</td>
<td><asp:TextBox ID="retypeTB" runat="server" ></asp:TextBox></td>
</tr>

<tr align="center">
<td colspan="2"><asp:Button ID="registerBTN" runat="server" Text="Register" /></td>
</tr>
</table>
</div>
</asp:Content>

