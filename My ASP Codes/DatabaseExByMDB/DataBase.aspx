<%@ Page Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="DataBase.aspx.cs" Inherits="DataBase" Title="Untitled Page" %>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
<br /><br />

<table width="500px" border="1" cellpadding="5" cellspacing="0" align="center">
<tr>
<td style="background-color:White;"><u><b>DATABASE</b></u></td>
</tr>
<tr>
<td>
<asp:Table ID="Table1" runat="server" GridLines="Both" Width="500px"></asp:Table>
</td>
</tr>
<tr>
<th><asp:Button ID="Button1" runat="server" Text="Show Data" 
        onclick="Button1_Click" /></th>
</tr>
</table>
<asp:AccessDataSource ID="AccessDataSource1" runat="server" 
        DataSourceMode="DataReader" DataFile="~/App_Data/studentDatabase.mdb" 
        SelectCommand="SELECT * FROM [student]">

</asp:AccessDataSource>
</asp:Content>

