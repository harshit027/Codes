<%@ Control Language="C#" AutoEventWireup="true" CodeFile="LoginControl.ascx.cs" Inherits="controls_LoginControl" %>
<table width="250" border="1" cellspacing="0" cellpadding="3" style="background-color:Black; color:White; font-family:Verdana; font-size:small">
<tr style="background-color:Gray; color:Black; font-family:Times New Roman; font-size:medium;">
<th colspan="2">
LOGIN
</th>
</tr>
<tr>
<td>
Username
</td>
<td>
<asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
</td>
</tr>
<tr>
<td>
    Password
</td>
<td>
<asp:TextBox ID="TextBox2" TextMode="Password" runat="server"></asp:TextBox>
</td>
</tr>
<tr align="center">
<td colspan="2">
<asp:Label ID="Label1" runat="server" Text="" Visible="false"></asp:Label><br />
<asp:Button ID="Button1" runat="server" Text="Login" onclick="Button1_Click" />
</td>

</tr>
</table>