<%@ Page Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="DataPage.aspx.cs" Inherits="DataPage" Title="Untitled Page" %>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
<br /><br />
<table width="600px" align="center" border="2" cellspacing="0" cellpadding="5">
<tr style="background-color:White;">
<th><u>DATABASE</u></th>
</tr>
<tr>
<th>
<asp:Table ID="Table1" runat="server" GridLines="Both" Width="600px">
</asp:Table>
</th>
</tr>
</table>

</asp:Content>

