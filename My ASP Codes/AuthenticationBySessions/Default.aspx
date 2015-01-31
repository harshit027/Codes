<%@ Page Language="C#" AutoEventWireup="true" MasterPageFile="~/MasterPage.master"  CodeFile="Default.aspx.cs" Inherits="_Default" %>

<asp:Content ID="Content1" runat="server" ContentPlaceHolderID="ContentPlaceHolder1">
<br /><br />

<table width="500px" align="center" cellpadding="5" cellspacing="0" border="1">
<tr>
<th colspan="2"><u>REGISTER</u></th>
</tr>
<tr>
<td>DoctorID : </td>
<td><asp:TextBox ID="TextBox1" runat="server" ReadOnly="true"></asp:TextBox></td>
</tr>
<tr>
<td>Name : </td>
<td><asp:TextBox ID="TextBox2" runat="server"></asp:TextBox></td>
</tr>
<tr>
<td>Password : </td>
<td><asp:TextBox ID="TextBox3" runat="server"></asp:TextBox></td>
</tr>
<tr>
<td>Degree : </td>
<td><asp:TextBox ID="TextBox4" runat="server"></asp:TextBox></td>
</tr>
<tr>
<td>Specialization : </td>
<td><asp:TextBox ID="TextBox5" runat="server"></asp:TextBox></td>
</tr>
<tr>
<th colspan="2"><asp:Button ID="Save" runat="server" Text="Save" 
        onclick="Save_Click" />&nbsp;&nbsp;
        <asp:Button ID="Reset" runat="server" Text="Reset" 
   onclick="Reset_Click" /></th>
</tr>
</table>
</asp:Content>

