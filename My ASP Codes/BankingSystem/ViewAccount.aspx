<%@ Page Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="ViewAccount.aspx.cs" Inherits="ViewAccount" Title="Untitled Page" %>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
<br />
<table  align="center" border="2">
<tr>
<td>
<asp:GridView ID="GridView1" runat="server" CellPadding="4" AllowPaging="True"  onpageindexchanging="NewPage"
        BackColor="White" BorderColor="#CC9966" BorderStyle="None" BorderWidth="1px" 
        PageSize="5">
    <FooterStyle BackColor="#FFFFCC" ForeColor="#330099" />
    <RowStyle BackColor="White" ForeColor="#330099" />
    <PagerStyle BackColor="#FFFFCC" ForeColor="#330099" HorizontalAlign="Center" />
    <SelectedRowStyle BackColor="#FFCC66" Font-Bold="True" ForeColor="#663399" />
    <HeaderStyle BackColor="#990000" Font-Bold="True" ForeColor="#FFFFCC" />
    </asp:GridView>
</td>
</tr>
</table>

</asp:Content>

