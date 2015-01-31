<%@ Page Language="C#" AutoEventWireup="true"  MasterPageFile="~/MasterPage.master" CodeFile="Default.aspx.cs" Inherits="_Default" %>

<asp:Content ID="c1" runat="server" ContentPlaceHolderID="ContentPlaceHolder1">
 <center>   
<asp:Table ID="Table1" runat="server" BorderStyle="Double" GridLines="Both">
<asp:TableRow>
<asp:TableHeaderCell>
<table width="300" border="2" cellspacing="0" align="center" cellpadding="10">
<tr align="center"  >
<th>Name</th>
<th>Branch</th>
<th>College</th>
</tr>
<tr align="center">
<td>Harshit</td>
<td>IT</td>
<td>JEC</td>
</tr>
<tr align="center">
<td>Harshit</td>
<td>IT</td>
<td>JEC</td>
</tr>
<tr align="center">
<td>Harshit</td>
<td>IT</td>
<td>JEC</td>
</tr>
<tr align="center">
<td>Harshit</td>
<td>IT</td>
<td>JEC</td>
</tr><br />
<tr align="center">
<td colspan=3>
<asp:Button ID="Button1" runat="server" Text="ChangeTableColor" OnClick="ChangeColor" /> 
</td>
</tr>
</table>
</asp:TableHeaderCell>
</asp:TableRow>
</asp:Table>
</center>
<asp:HiddenField ID="HiddenField1" Value="0" runat="server" />

</asp:Content>
